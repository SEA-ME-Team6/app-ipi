#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/instrument_cluster.ini"

$SCRIPT_DIR/instrument_cluster -platform linuxfb
# $SCRIPT_DIR/../build/instrument_cluster/instrument_cluster

