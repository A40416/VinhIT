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
const vscode = require("vscode");
function configureSettings(config, force = false) {
    return __awaiter(this, void 0, void 0, function* () {
        if (config.username === null || force) {
            const resp = yield vscode.window.showInputBox({ prompt: "Type EPITECH username: " });
            if (resp !== undefined) {
                config.update("username", resp, true);
            }
        }
        if (config.login === null || force) {
            const resp = yield vscode.window.showInputBox({ prompt: "Type EPITECH login: " });
            if (resp !== undefined) {
                config.update("login", resp, true);
            }
        }
        {
            const resp = yield vscode.window.showQuickPick(["Post 2017", "Pre 2017"], { placeHolder: "Select the header format to use:" });
            config.update("headerType", resp.replace(/\s+/g, '').toLowerCase(), true);
        }
        {
            const resp = yield vscode.window.showInformationMessage("Which header guard do you want to use ?", "#ifndef/#endif", "#pragma once");
            if (resp !== undefined) {
                config.update("usePragmaOnce", resp == "#pragma once", true);
            }
        }
        {
            const resp = yield vscode.window.showInformationMessage("Do you want automatic C++ class generation ?", "Yes", "No");
            if (resp !== undefined) {
                config.update("autoGenerateClasses", resp == "Yes", true);
            }
            if (resp == "Yes") {
                const indentResp = yield vscode.window.showInformationMessage("Do you want public, protected and private keywords to be indented ?", "Yes", "No");
                if (indentResp !== undefined) {
                    config.update("indentAccessSpecifiers", indentResp == "Yes", true);
                }
            }
        }
        vscode.window.showInformationMessage("EPITECH headers have been successfully configured !");
    });
}
exports.configureSettings = configureSettings;
function loadConfig() {
    const config = {};
    config.handle = vscode.workspace.getConfiguration("epitech-c-cpp-headers");
    config.username = (config.handle.username === null) ? os.userInfo().username : config.handle.username;
    config.login = (config.handle.login === null) ? "" : config.handle.login;
    config.headerType = config.handle.headerType || "post2017";
    config.usePragmaOnce = config.handle.usePragmaOnce || false;
    config.autoGenerateClasses = config.handle.autoGenerateClasses || true;
    config.indentAccessSpecifiers = config.handle.indentAccessSpecifiers;
    return config;
}
exports.loadConfig = loadConfig;
//# sourceMappingURL=config.js.map