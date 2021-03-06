const vscode = require('vscode');

function includeGuard() {
    const editor = vscode.window.activeTextEditor;
    if (!editor) {
        return;
    }

    editor.edit(editBuilder => {
        const { document } = editor;
        const { start } = document.lineAt(0).range;
        const definition = getIncludeGuardDefine();
        editBuilder.insert(start, getIncludeGuardStart(definition));
        const { end } = document.lineAt(document.lineCount - 1).range;
        editBuilder.insert(end, getIncludeGuardEnd(definition));
    });
}

function getIncludeGuardStart(definition) {
    return `#ifndef ${definition}\n#define ${definition}\n\n`;
}

function getIncludeGuardEnd(definition) {
    return `\n#endif${getComment(definition)}\n`;
}

function getIncludeGuardDefine(path) {
    path = path || vscode.window.activeTextEditor.document.fileName;
    const config = vscode.workspace.getConfiguration();
    const prefix = config.get('cpp_assist.includeGuard.prefix');
    let suffix = config.get('cpp_assist.includeGuard.suffix');
    if (config.get('cpp_assist.includeGuard.random')) {
        suffix = '_' + randomStr() + suffix;
    }

    return prefix + toDefineCase(path.replace(/.*[\\\/-]/g, '')) + suffix;
}

function toDefineCase(str) {
    return str.replace(/(?:^|\.?)([A-Z])/g, '_$1').replace('.', '_').replace(/^_/, "").toUpperCase();
}

function randomStr(length = 12) {
    let result = '';
    const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
    const charactersLength = characters.length;
    for (let i = 0; i < length; i++) {
        result += characters.charAt(Math.floor(Math.random() * charactersLength));
    }
    return result;
}

function getComment(definition) {
    const config = vscode.workspace.getConfiguration();
    const commentStyle = config.get('cpp_assist.includeGuard.commentStyle');
    const spaces = ' '.repeat(config.get('cpp_assist.includeGuard.spacesBeforeComment'));
    if (commentStyle === 'None') {
        return '';
    }
    return ((commentStyle === 'line comment')
        ? `${spaces}// ${definition}`
        : `${spaces}/* ${definition} */`);
}

module.exports = {
    includeGuard,
    getIncludeGuardStart,
    getIncludeGuardEnd,
    getIncludeGuardDefine
};
