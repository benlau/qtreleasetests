QT       += testlib qml qmltest

TARGET = qtbug-62666
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += warn_on qmltestcase

TEMPLATE = app

IMPORTPATH = $$PWD

SOURCES += \
    main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DISTFILES += \
    tst_QtBug62666.qml
