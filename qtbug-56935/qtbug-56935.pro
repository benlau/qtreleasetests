QT       += testlib qml qmltest gui quick

TARGET = qtbug-56935
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += warn_on qmltestcase

TEMPLATE = app

IMPORTPATH = $$PWD

SOURCES += \
    main.cpp \
    adapter.cpp \
    screencontroller.cpp \
    viewer.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DISTFILES += \
    tst_Sample.qml \
    Dummy1.qml

HEADERS += \
    adapter.h \
    screencontroller.h \
    viewer.h

RESOURCES += \
    qml.qrc
