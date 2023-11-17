#!/bin/sh

# Virtual CAN
sudo modprobe vcan
sudo ip link add dev can0 type vcan
sudo ip link set up can0

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/rpm_sender.ini"

# $SCRIPT_DIR/build/rpm_sender -platform eglfs
$SCRIPT_DIR/../build/rpm_sender/rpm_sender

