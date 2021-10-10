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
exports.deactivate = exports.activate = void 0;
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require("vscode");
const fs = require("fs");
const path = require("path");
function create_name_input() {
    return __awaiter(this, void 0, void 0, function* () {
        var option = {
            ignoreFocusOut: false,
            placeHolder: "foo it in the bar.",
            prompt: "Type your class name"
        };
        return vscode.window.showInputBox(option);
    });
}
function create_path_input() {
    return __awaiter(this, void 0, void 0, function* () {
        var option = {
            ignoreFocusOut: false,
            placeHolder: "Give me your path.",
            prompt: "Type a valid path"
        };
        return yield vscode.window.showInputBox(option);
    });
}
function create_hpp_buffer(name) {
    const ifndef_head = `#ifndef ` + name.toUpperCase() + `_H
#define ` + name.toUpperCase() + `_H`;
    const pragma_once_buffer = `
#pragma once`;
    const default_info = `
	
class ` + name + `  
{
	private:

	public:

		` + name + `();
		~` + name + `();

};`;
    const ifndef_end = `
#endif`;
    var output;
    const useIfnDef = vscode.workspace.getConfiguration().get("cpp.creator.headerProtection.useIfnDef");
    const usePragma = vscode.workspace.getConfiguration().get("cpp.creator.headerProtection.usePragmaOnce");
    if (useIfnDef && usePragma) {
        output = ifndef_head + pragma_once_buffer + default_info + ifndef_end;
    }
    else if (useIfnDef) {
        output = ifndef_head + default_info + ifndef_end;
    }
    else if (usePragma) {
        output = pragma_once_buffer + default_info;
    }
    else {
        output = default_info;
    }
    return output;
}
function get_include_name(name) {
    var include_name;
    if (vscode.workspace.getConfiguration().get("cpp.creator.useHPPEnding") === true) {
        include_name = name + '.hpp';
    }
    else {
        include_name = name + '.h';
    }
    return include_name;
}
function create_hpp(name, dir) {
    var hpp_buffer = create_hpp_buffer(name);
    var hpp_name = dir + "/" + get_include_name(name);
    fs.writeFile(hpp_name, hpp_buffer, function (err) {
        if (err) {
            console.error(err);
            return false;
        }
    });
    return true;
}
function create_cpp_buffer(name) {
    var hpp_name = get_include_name(name);
    var cpp_buffer = `#include "` + hpp_name + `"  
	
` + name + `::` + name + `()
{
	
}
	
` + name + `::~` + name + `()
{
	
}`;
    return cpp_buffer;
}
function create_cpp(name, dir) {
    var cpp_buffer = create_cpp_buffer(name);
    var cpp_name = dir + "/" + name + '.cpp';
    fs.writeFile(cpp_name, cpp_buffer, function (err) {
        if (err) {
            console.error(err);
            return false;
        }
    });
    return true;
}
function create_class(name, dir) {
    if (fs.existsSync(dir)) {
        var stats = fs.lstatSync(dir);
        if (!stats.isDirectory()) {
            return false; // if the give directory path, isnt a directory, you cant create a class
        }
    }
    else
        fs.mkdirSync(dir); // if the path doesnt exist, just create the directory
    var hpp = create_hpp(name, dir);
    var cpp = create_cpp(name, dir);
    return (hpp && cpp);
}
function can_continue(res) {
    if (!res) {
        vscode.window.showErrorMessage("Your Class could not be created!");
        return false;
    }
    else if (res.length > 60) {
        vscode.window.showErrorMessage("Class name to long!");
        return false;
    }
    else if (res.indexOf(' ') >= 0) {
        vscode.window.showErrorMessage("Class name should not have spaces!");
        return false;
    }
    return true;
}
// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
function activate(context) {
    return __awaiter(this, void 0, void 0, function* () {
        // Use the console to output diagnostic information (console.log) and errors (console.error)
        // This line of code will only be executed once when your extension is activated
        console.log('Congratulations, your extension "cpp-class-creator" is now active!');
        let disposable = vscode.commands.registerCommand('extension.createClass', (args) => __awaiter(this, void 0, void 0, function* () {
            // The code you place here will be executed every time your command is executed
            var res = yield create_name_input();
            if (!can_continue(res))
                return; // check for class name
            let dir = vscode.workspace.getConfiguration().get("cpp.creator.setPath");
            // If it's called via the context menu, it's gonna have the _fsPath set from where you're clicking
            if (args != null && args._fsPath != null) {
                dir = args._fsPath;
                if (typeof dir === "string" && fs.existsSync(dir)) {
                    var stats = fs.lstatSync(dir);
                    if (!stats.isDirectory()) {
                        //If it's not a directory then it's the file so get the parent directory
                        dir = path.dirname(args._fsPath);
                    }
                }
            }
            if (dir == null || dir == false) {
                dir = vscode.workspace.rootPath; // use workspace path
                let createFolder = vscode.workspace.getConfiguration().get("cpp.creator.createFolder");
                if (createFolder) // create the folder where to put the class
                    dir += "/" + res;
            }
            else if (dir == true) {
                dir = yield create_path_input(); // ask for path
                if (!dir) {
                    dir = vscode.workspace.rootPath; // if empty input, just use workspace path
                }
            }
            var out = create_class(res, dir); // if setPath was neither false, null or true, it was a string, so maybe a valid path? 
            //Create the class there
            if (out) {
                vscode.window.showInformationMessage('Your Class ' + res + '  has been created!');
            }
            else {
                vscode.window.showErrorMessage('Your Class ' + res + '  has been not created!');
            }
        }));
        // Display a message box to the user
        context.subscriptions.push(disposable);
    });
}
exports.activate = activate;
// this method is called when your extension is deactivated
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map