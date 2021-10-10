"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
// Create header guard command
function default_1() {
    var _a;
    if (vscode.window.activeTextEditor && vscode.window.activeTextEditor.selection) {
        let fileName = (_a = vscode.window.activeTextEditor) === null || _a === void 0 ? void 0 : _a.document.fileName;
        let name = fileName.replace(/^.*[\\\/]/, '').replace(/\.[^\.]+$/, '');
        let headerGuard = vscode.workspace.getConfiguration("CppHelper").get('HeaderGuardPattern');
        headerGuard = headerGuard.replace('{FILE}', name.toUpperCase());
        if (vscode.window.activeTextEditor) {
            vscode.window.activeTextEditor.insertSnippet(new vscode.SnippetString('\n#endif // ' + headerGuard), vscode.window.activeTextEditor.document.positionAt(vscode.window.activeTextEditor.document.getText().length));
            vscode.window.activeTextEditor.insertSnippet(new vscode.SnippetString('#ifndef ' + headerGuard + '\n#define ' + headerGuard + '\n\n'), vscode.window.activeTextEditor.document.positionAt(0));
        }
    }
}
exports.default = default_1;
//# sourceMappingURL=CreateHeaderGuard.js.map