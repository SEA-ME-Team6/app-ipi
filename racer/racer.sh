#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/racer.ini"

# $SCRIPT_DIR/build/racer -platform eglfs
$SCRIPT_DIR/../build/racer/racer

