var shell = require('shelljs');
var argv = require('optimist').argv;
var xml2js = require('xml2js');

var input = argv._[0];
var name = argv._[1];
var packageName = argv._[2];
var content  = shell.cat(input).toString();

var parser = new xml2js.Parser();
var data;

parser.parseString(content, function (err, result) {
    data = result;
});

var packages = data.Packages.Package;

var index = packages.findIndex(function(o) { return o.Name[0] === packageName});

if (index < 0) {
    console.error(packageName, "not found");
    console.log(JSON.stringify(packages,null,4));
    return -1;
}

var package = packages[index];

var output = {
    name: name,
    version: package.Version[0],
    tests: []    
}

shell.ShellString(JSON.stringify(output,null,4)).to("result.json");

