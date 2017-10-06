#!/bin/sh

rm -rf build
mkdir build
cd build
echo Run $1
run-unittests $1

