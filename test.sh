#!/bin/sh

rm -rf build
mkdir build
cd build
echo Run $1
QT_CI_SILENT=true run-unittests $1

