#!/bin/bash

rm -rf build
mkdir build
cd build
QT_CI_SILENT=true run-unittestsa --qpa-platform minimal $2 2>&1 | tee log
CODE=${PIPESTATUS[0]} 
cd -

if [ $CODE -eq 0 ]; then
    node logger/add.js "$1" pass
else
    node logger/add.js "$1" fail build/log
    exit -1
fi

