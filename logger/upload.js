var Hubdb = require('hubdb');
var argv = require('optimist').argv;
var shell = require('shelljs');

var db = Hubdb({
 token: process.env.GITHUB_TOKEN,
 username: 'benlau',
 repo: 'qtbugstatus',
 branch: 'db'
});

var name = argv._[0];
var content = JSON.parse(shell.cat("result.json").toString());

db.list(function(err,res) {
   
    var index = res.findIndex(function(o) {
        return o.data.name === name;    
    });
    
    function callback(err, res, id) {
        if (err) {
            console.log(err);
        } else {
            console.log("updated");
        }
    }
    
    if (index < 0) {
        db.add(content, callback);
    } else {
        var item = res[index];
        db.update(item.path, content, callback);
    }
    
});
