import QtQuick 2.3
import QtTest 1.0

TestCase {
    name: "QtBug62666"
    property var foo

    function test_case1() {
        console.log("case1");
        foo = {"key1":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "key2":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "key3":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "key4":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "key5":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "key6":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                "key7":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}
         var keys = Object.keys(foo)
         for (var i = 0; i < keys.length; i++)
           delete foo[keys[i]]

         gc() // Direct call not required, it also fails on subsequent automatic gc
    }

    function test_case2() {
        console.log("case2");

        foo = {"key1":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "key2":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "key3":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "key4":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "key5":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "key6":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "key7":"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}
        var keys = Object.keys(foo)
        for (var i = 0; i < keys.length; i++)
          delete foo[keys[i]]

        // Alternative to manual gc call — just do some stuff, it also crashes
        var x;
        for (var j = 0; j < 1000; j++)
          x = Array(200).join('0')
    }


    function test_case3() {
        console.log("case3");

        var foo = {a:0,b:0,c:0,d:0,e:0,f:0,g:0}
        var bar = [] // this somehow affects the crash
        delete foo.a; delete foo.b; delete foo.c; delete foo.d
        delete foo.e; delete foo.f; delete foo.g
        gc() // Direct call not required, it also fails on subsequent automatic gc
    }
}
