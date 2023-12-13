#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/gamepad.ini"

$SCRIPT_DIR/../build/Virtual_gamepad/Virtual_gamepad
# $SCRIPT_DIR/gamepad

