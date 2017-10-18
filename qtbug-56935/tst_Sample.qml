import QtQuick 2.3
import QtTest 1.0
import Adapter 1.0

TestCase {
    name: "Sample"

    function test_pass() {

        for (var i = 0 ; i < 1000;i++) {
            Adapter.clearComponentCache();
        }
    }
}
