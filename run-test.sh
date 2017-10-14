#!/bin/sh

rm -rf build
mkdir build
cd build
QT_CI_SILENT=true run-unittests $2
cd -

if [ $? -eq 0 ]; then
    node logger/add.js "$1" pass
else
    node logger/add.js "$1" fail
fi

