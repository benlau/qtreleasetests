import QtQuick 2.3
import QtTest 1.0
import "./stores"

TestCase {
    name: "QtBug49370"

    function test_pass() {
        compare(B.objectName, "B");
        compare(C.objectName, "C");
    }
}
