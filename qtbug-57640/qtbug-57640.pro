QT       += testlib qml qmltest

TARGET = qtbug-57640
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += warn_on qmltestcase

TEMPLATE = app

IMPORTPATH = $$PWD

SOURCES += \
    main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DISTFILES += \
    tst_bug.qml
