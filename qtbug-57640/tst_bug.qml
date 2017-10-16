import QtQuick 2.3
import QtTest 1.0
import "./lodash.js" as Lodash
import "./shortexample2.js" as ShortExample2
import "./shortexample1.js" as ShortExample1

TestCase {
    name: "QtBug57640"

    function test_pass() {
        console.log(Lodash, ShortExample1, ShortExample2);
        compare(true, true);
    }
}
