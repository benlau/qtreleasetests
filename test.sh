#!/bin/sh

rm -rf build
mkdir build
cd build
QT_CI_SILENT=true run-unittests $1

