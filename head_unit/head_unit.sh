#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/head-unit.ini"

# $SCRIPT_DIR/head_unit -platform eglfs
$SCRIPT_DIR/../build/head_unit/head_unit


