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
const path = require("path");
const vscode = require("vscode");
const config_1 = require("./config");
const constants_1 = require("./constants");
const generators_1 = require("./generators");
const misc_1 = require("./misc");
function activate(context) {
    const extConfig = vscode.workspace.getConfiguration("epitech-c-cpp-headers");
    if (extConfig.prompt === true && (extConfig.username === null || extConfig.login === null || extConfig.headerType === null)) {
        (() => __awaiter(this, void 0, void 0, function* () {
            const resp = yield vscode.window.showInformationMessage("Do you want to quickly set up EPITECH headers ?", "Yes", "No");
            if (resp === "Yes") {
                config_1.configureSettings(extConfig);
            }
        }))();
    }
    const disposables = [
        vscode.commands.registerCommand('epitech-c-cpp-headers.addHeader', () => __awaiter(this, void 0, void 0, function* () {
            const date = new Date();
            const fileInfo = {};
            fileInfo.editor = vscode.window.activeTextEditor;
            fileInfo.document = fileInfo.editor.document;
            fileInfo.fileName = fileInfo.document.fileName;
            fileInfo.uri = fileInfo.document.uri;
            fileInfo.eol = constants_1.EOLS[fileInfo.document.eol];
            fileInfo.ext = path.basename(fileInfo.fileName).split(".").reverse()[0];
            if (!(fileInfo.ext in constants_1.SUPPORTED_LANGUAGES)) {
                vscode.window.showErrorMessage("The currently opened file isn't a supported file.");
                return;
            }
            fileInfo.langId = constants_1.SUPPORTED_LANGUAGES[fileInfo.ext];
            fileInfo.projName = yield vscode.window.showInputBox({
                prompt: "Type project name: ",
                placeHolder: "Leave empty to generate one based on workspace name...",
            });
            if (fileInfo.projName === undefined) {
                vscode.window.showInformationMessage("Operation canceled !");
                return;
            }
            else if (fileInfo.projName === '') {
                fileInfo.projName = vscode.workspace.name;
            }
            const config = config_1.loadConfig();
            if (config.headerType == "post2017") {
                fileInfo.description = yield vscode.window.showInputBox({
                    prompt: "Type project description: ",
                    placeHolder: "Leave empty to generate one based on filename...",
                });
                if (fileInfo.description === undefined) {
                    vscode.window.showInformationMessage("Operation canceled !");
                    return;
                }
                else if (fileInfo.description === '') {
                    const basename = path.basename(fileInfo.fileName);
                    if (/^[^\.]+\..+$/.test(basename)) {
                        fileInfo.description = basename.slice(0, -(fileInfo.ext.length + 1));
                    }
                    else {
                        fileInfo.description = basename;
                    }
                }
            }
            let editContent = generators_1.generate[config.headerType](fileInfo, config, date);
            let offsetY = constants_1.SYNTAX[config.headerType].offsetHeaderFile;
            let offsetX = 0;
            const isEmptyHeaderFile = (fileInfo.document.getText() == '' && fileInfo.ext.match(/^(?:h|hpp|H|hh)$/));
            const isEmptySourceFile = (fileInfo.document.getText() == '' && fileInfo.ext.match(/^(?:c|cpp|C|cc)$/));
            if (isEmptyHeaderFile) {
                const base = path.basename(fileInfo.fileName);
                const className = base.substr(0, base.length - fileInfo.ext.length - 1);
                let name = undefined;
                if (config.usePragmaOnce) {
                    editContent = editContent.concat("#pragma once", fileInfo.eol, fileInfo.eol);
                }
                else {
                    name = yield vscode.window.showInputBox({
                        prompt: "Type header guard's name: ",
                        placeHolder: "Leave empty to generate one based on filename...",
                        validateInput: name => {
                            const results = /([^A-Za-z0-9_])/.exec(name);
                            if (!results) {
                                return undefined;
                            }
                            else {
                                return `'${results[0]}' isn't valid.
                                    Only alphanumeric characters and '_' are allowed in header guards.
                                    Please try again with a valid name or leave empty to generate one based on the filename.`;
                            }
                        },
                    });
                    if (name === undefined) {
                        vscode.window.showInformationMessage("Operation canceled !");
                        return;
                    }
                    name = name || base.replace(/[^A-Za-z0-9]/g, "_").concat("_").toLocaleUpperCase();
                    editContent = generators_1.appendIfndef(editContent, name, fileInfo, config);
                }
                if (config.autoGenerateClasses && fileInfo.langId == "cpp" && misc_1.isUpper(className[0])) {
                    editContent = generators_1.appendClass(editContent, className, fileInfo, config);
                    offsetY += 3 + Number(config.usePragmaOnce == false);
                    offsetX = 0;
                }
                if (!config.usePragmaOnce) {
                    editContent = editContent.concat(fileInfo.eol, "#endif /* !", name, " */", fileInfo.eol);
                }
            }
            if (isEmptySourceFile) {
                const name = path.basename(fileInfo.fileName).replace(/[^A-Za-z0-9]/g, "_").concat("_");
                const className = path.basename(fileInfo.fileName).substr(0, name.length - fileInfo.ext.length - 2);
                if (config.autoGenerateClasses && fileInfo.langId == "cpp" && misc_1.isUpper(className[0])) {
                    editContent = generators_1.appendConstructorDestructor(editContent, className, fileInfo);
                }
            }
            const edit = new vscode.WorkspaceEdit();
            edit.set(fileInfo.uri, [vscode.TextEdit.insert(new vscode.Position(0, 0), editContent)]);
            vscode.workspace.applyEdit(edit);
            if (isEmptyHeaderFile) {
                const pos = new vscode.Position(offsetY, offsetX);
                fileInfo.editor.selection = new vscode.Selection(pos, pos);
            }
        })),
        vscode.commands.registerCommand('epitech-c-cpp-headers.setConfig', () => {
            config_1.configureSettings(vscode.workspace.getConfiguration("epitech-c-cpp-headers"), true);
        }),
    ];
    context.subscriptions.push(...disposables);
    vscode.workspace.onWillSaveTextDocument(ev => ev.waitUntil(generators_1.updateHeader(ev)));
}
exports.activate = activate;
function deactivate() {
}
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map