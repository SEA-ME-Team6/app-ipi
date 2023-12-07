#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/head-unit.ini"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/seame-workstation08/DES_Head-Unit/build

appman --builtin-apps-manifest-dir ./apps system-ui/system-ui.qml


