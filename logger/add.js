var shell = require('shelljs');
var argv = require('optimist').argv;

var name = argv._[0];
var result = argv._[1];


function removeNonPrintableChar(txt) {
    return txt.replace(/[\x00-\x09\x0B-\x0C\x0E-\x1F\x7F-\x9F]/g, '');
}

var content = shell.cat("result.json").toString();
content = removeNonPrintableChar(content);
content = JSON.parse(content);

var test = {
    name: name,
    pass: result === "pass"
}

if (!test.pass) {
    var reason = shell.cat(argv._[2]).toString();
    test.reason = reason;
}

content.tests.push(test);

shell.ShellString(JSON.stringify(content,null,4)).to("result.json");
console.log(name + " : " + result);
console.log("Updated result.json");