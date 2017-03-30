#!/bin/sh

rm -rf build
mkdir build
cd build
run-unittests $1

