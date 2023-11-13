#!/bin/sh

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/racer/racer.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build/racer"
# $SCRIPT_DIR/build/racer/racer -platform eglfs
$SCRIPT_DIR/build/racer/racer


export COMMONAPI_CONFIG="$SCRIPT_DIR/gamepad/gamepad.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build/gamepad"
# $SCRIPT_DIR/build/gamepad/gamepad -platform eglfs
$SCRIPT_DIR/build/gamepad/gamepad

'''
export COMMONAPI_CONFIG="$SCRIPT_DIR/head_unit/head_unit.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build/head_unit"
# $SCRIPT_DIR/build/head_unit/head_unit -platform eglfs
$SCRIPT_DIR/build/head_unit/head_unit

export COMMONAPI_CONFIG="$SCRIPT_DIR/speed_sender/speed_sender.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build/speed_sender"
# $SCRIPT_DIR/build/speed_sender/speed_sender -platform eglfs
$SCRIPT_DIR/build/speed_sender/speed_sender

export COMMONAPI_CONFIG="$SCRIPT_DIR/instrument_cluster/instrument_cluster.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build/instrument_cluster"
# $SCRIPT_DIR/build/speed_sender -platform eglfs
$SCRIPT_DIR/build/instrument_cluster/instrument_cluster
'''
