import QtQuick 2.3
import QtTest 1.0
import Adapter 1.0

TestCase {
    name: "Sample"

    Loader {
        id: loader
    }

    function test_pass() {

        for (var i = 0 ; i < 1000;i++) {
            loader.source = Qt.resolvedUrl("./Dummy1.qml");
            Adapter.clearComponentCache();
        }
    }
}
