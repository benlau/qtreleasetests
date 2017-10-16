QT       += testlib qml qmltest concurrent

TARGET = qtbug-49370
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += warn_on qmltestcase

TEMPLATE = app

IMPORTPATH = $$PWD

SOURCES += \
    main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DISTFILES += \
    tst_qtbug49370.qml \
    stores/qmldir \
    stores/A.qml \
    stores/B.qml \
    stores/C.qml
