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
const iconv = require("iconv-lite");
const logger_1 = require("../logger");
const spawnSync = require('child_process').spawnSync;
const util = require('util');
const exec = util.promisify(require('child_process').exec);
class ExecutableBase {
    constructor(configuration) {
        this.configuration = configuration;
    }
    /* Execute 'executable args' and return stdout with line split */
    execute(args, cwd = undefined, env = {}) {
        /* default add the PATH to the env */
        env = Object.assign(Object.assign({}, env), process.env);
        const options = {
            cwd: cwd,
            env: env,
            encoding: 'binary'
        };
        console.log(this.executable + " " + args.join(' ') + "\n");
        let sync = spawnSync(this.executable, args, options);
        if (sync.error) {
            throw sync.error;
        }
        else if (0 !== sync.status) {
            throw sync.stderr.toString();
        }
        logger_1.default.info(this.executable + " " + args + "\n" + sync.stdout);
        console.log(sync.stdout);
        const encoding = this.configuration.encoding.get();
        return iconv.decode(Buffer.from(sync.stdout, 'binary'), encoding).split(/\r?\n/);
    }
    execute_async(args, cwd = undefined, env = {}) {
        return __awaiter(this, void 0, void 0, function* () {
            /* default add the PATH to the env */
            env = Object.assign(Object.assign({}, env), process.env);
            const options = {
                cwd: cwd,
                env: env,
                encoding: 'binary',
                maxBuffer: 2 * 1024 * 1024
            };
            const { stdout, stderr } = yield exec(this.executable + ' ' + args.join(' '), options);
            if (stderr) {
                console.log("stderr: " + stderr);
            }
            const encoding = this.configuration.encoding.get();
            return iconv.decode(Buffer.from(stdout, 'binary'), encoding).split(/\r?\n/);
        });
    }
}
exports.default = ExecutableBase;
//# sourceMappingURL=executableBase.js.map