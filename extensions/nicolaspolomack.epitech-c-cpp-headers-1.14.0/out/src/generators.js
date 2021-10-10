"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const os = require("os");
const path = require("path");
const vscode = require("vscode");
const escapeRegExpString = require("escape-string-regexp");
const constants_1 = require("./constants");
exports.generate = {
    pre2017: generatePre2017Header,
    post2017: generatePost2017Header
};
function generatePre2017Header(fileInfo, config, date) {
    const editContent = "";
    return editContent
        .concat(constants_1.SYNTAX.commentStart[fileInfo.langId], fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", path.basename(fileInfo.fileName), constants_1.SYNTAX.pre2017.headerFor, fileInfo.projName, constants_1.SYNTAX.pre2017.headerIn, path.dirname(fileInfo.fileName), fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", constants_1.SYNTAX.pre2017.headerMadeBy, config.username, fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", constants_1.SYNTAX.pre2017.headerLogin, constants_1.SYNTAX.pre2017.headerLoginBeg, config.login, constants_1.SYNTAX.pre2017.headerLoginMid, constants_1.SYNTAX.pre2017.domaineName, constants_1.SYNTAX.pre2017.headerLoginEnd, fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", constants_1.SYNTAX.pre2017.headerStarted, constants_1.DAYS[date.getDay() - 1], " ", constants_1.MONTHS[date.getMonth()], " ", date.getDate().toString(), " ", date.toLocaleTimeString(), " ", date.getFullYear().toString(), " ", config.username, fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", constants_1.SYNTAX.pre2017.headerLast, constants_1.DAYS[date.getDay() - 1], " ", constants_1.MONTHS[date.getMonth()], " ", date.getDate().toString(), " ", date.toLocaleTimeString(), " ", date.getFullYear().toString(), " ", config.username, fileInfo.eol, constants_1.SYNTAX.commentEnd[fileInfo.langId], fileInfo.eol, fileInfo.eol);
}
function generatePost2017Header(fileInfo, config, date) {
    const editContent = "";
    return editContent.concat(constants_1.SYNTAX.commentStart[fileInfo.langId], fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", "EPITECH PROJECT, ", date.getFullYear().toString(), fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", fileInfo.projName, fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", "File description:", fileInfo.eol, constants_1.SYNTAX.commentMid[fileInfo.langId], " ", fileInfo.description, fileInfo.eol, constants_1.SYNTAX.commentEnd[fileInfo.langId], fileInfo.eol, fileInfo.eol);
}
// getTabType() generates a tab string based on the user's editors settings.
// If the insertSpaces setting is false : it will just return a '\t'.
// If it's set to true : it will check the tabSize setting and return a string of that length and made of whitespaces.
function getTabType() {
    const editor = vscode.window.activeTextEditor;
    const tabSize = editor.options.tabSize;
    let tab = "";
    if (!editor) {
        tab = "\t";
        return tab;
    }
    if (editor.options.insertSpaces) {
        if (tabSize)
            tab += " ".repeat(tabSize);
        else
            tab = "    ";
    }
    else
        tab = "\t";
    return tab;
}
// Generates a class with user-specified indentation style.
// If indentAccessSpecifiers is true (default) : "public", "protected" and "private" keywords will have an indentation of one tab.
// if set to false : they won't be indented at all.
function appendClass(editContent, className, fileInfo, config) {
    const tab = getTabType();
    const indent = (config.indentAccessSpecifiers) ? 1 : 0;
    return editContent.concat(`class ${className} {`, fileInfo.eol, tab.repeat(indent), 'public:', fileInfo.eol, tab.repeat(indent + 1), `${className}();`, fileInfo.eol, tab.repeat(indent + 1), `~${className}();`, fileInfo.eol, fileInfo.eol, tab.repeat(indent), 'protected:', fileInfo.eol, tab.repeat(indent), 'private:', fileInfo.eol, '};', fileInfo.eol);
}
exports.appendClass = appendClass;
function appendIfndef(editContent, id, fileInfo, config) {
    return editContent.concat(`#ifndef ${id}`, fileInfo.eol, `${constants_1.SYNTAX[config.headerType].preProcessorStyle}define ${id}`, fileInfo.eol, fileInfo.eol);
}
exports.appendIfndef = appendIfndef;
function appendConstructorDestructor(editContent, className, fileInfo) {
    const map = { "cpp": "hpp", "C": "H", "cc": "hh" };
    editContent = editContent.concat(`#include "${path.basename(fileInfo.fileName).replace("." + fileInfo.ext, "." + map[fileInfo.ext])}"`, fileInfo.eol, fileInfo.eol, `${className}::${className}()`, fileInfo.eol, '{', fileInfo.eol, '}', fileInfo.eol, fileInfo.eol, `${className}::~${className}()`, fileInfo.eol, "{", fileInfo.eol, "}", fileInfo.eol);
    return editContent;
}
exports.appendConstructorDestructor = appendConstructorDestructor;
function updateHeader(ev) {
    return __awaiter(this, void 0, void 0, function* () {
        const config = vscode.workspace.getConfiguration("epitech-c-cpp-headers");
        if (config.headerType == "post2017")
            return;
        let langId = path.basename(ev.document.fileName).split(".").reverse()[0];
        if (!(langId in constants_1.SUPPORTED_LANGUAGES))
            return;
        langId = constants_1.SUPPORTED_LANGUAGES[langId];
        const date = new Date();
        let username = vscode.workspace.getConfiguration("epitech-c-cpp-headers").username;
        username = (username === null) ? os.userInfo().username : username;
        const file = ev.document.getText();
        const regex = new RegExp(`(${escapeRegExpString(constants_1.SYNTAX.commentMid[langId])} ${escapeRegExpString(constants_1.SYNTAX.pre2017.headerLast)})(.*)(${constants_1.EOLS[ev.document.eol]})`);
        const match = regex.exec(file);
        if (match.length == 0)
            return;
        const editContent = constants_1.SYNTAX.commentMid[langId]
            .concat(" ", constants_1.SYNTAX.pre2017.headerLast, constants_1.DAYS[date.getDay()], " ", constants_1.MONTHS[date.getMonth()], " ", date.getDate().toString(), " ", date.toLocaleTimeString(), " ", date.getFullYear().toString(), " ", username, constants_1.EOLS[ev.document.eol]);
        const TextEdit = new vscode.TextEdit(new vscode.Range(ev.document.positionAt(match.index), ev.document.positionAt(match.index + match[0].length)), editContent);
        return [TextEdit];
    });
}
exports.updateHeader = updateHeader;
//# sourceMappingURL=generators.js.map