var shell = require('shelljs');
var argv = require('optimist').argv;

var name = argv._[0];
var result = argv._[1];

var content = JSON.parse(shell.cat("result.json").toString());

var test = {
    name: name,
    pass: result === "pass"
}

content.tests.push(test);

shell.ShellString(JSON.stringify(content,null,4)).to("result.json");
console.log(name + " : " + result);
console.log("Updated result.json");