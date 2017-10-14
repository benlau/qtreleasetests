var Hubdb = require('hubdb');
var argv = require('optimist').argv;
var shell = require('shelljs');

var db = Hubdb({
 token: process.env.GITHUB_TOKEN,
 username: 'benlau',
 repo: 'qtbugstatus',
 branch: 'db'
});

var content = JSON.parse(shell.cat("result.json").toString());

db.list(function(err,res) {
    console.log(content.name);
   
    var index = res.findIndex(function(o) {
        return o.data.name === content.name;    
    });
    
    function callback(err, res, id) {
        if (err) {
            console.log(err);
        } else {
            console.log("updated:" , id);
        }
    }
    
    if (index < 0) {
        console.log("add new record");
        db.add(content, callback);
    } else {
        var item = res[index];
        db.update(item.path, content, callback);
    }
    
});
