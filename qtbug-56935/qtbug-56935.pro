QT       += testlib qml qmltest

TARGET = qtbug-56935
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += warn_on qmltestcase

TEMPLATE = app

IMPORTPATH = $$PWD

SOURCES += \
    main.cpp \
    adapter.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DISTFILES += \
    tst_Sample.qml

HEADERS += \
    adapter.h
