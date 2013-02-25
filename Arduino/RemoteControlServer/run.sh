#!/bin/bash

# This script has to be modified with values in your environment

# Please set the path where arduino is installed
ARDUINO_PATH=/home/arduino-1.0.3
JAVA=$ARDUINO_PATH/java/bin/java
RXTX=$ARDUINO_PATH/lib/RXTXcomm.jar
# RXTX_LIB_PATH is where the rxtxSerial lib is located
RXTX_LIB_PATH=$ARDUINO_PATH
SERVER_PORT=80
SERIAL_PORT=COM4
echo Control+C to stop server
echo -n
$JAVA -cp .;$RXTX -Djava.library.path=$RXTX_LIB_PATH arduino.RemoteControlServer $SERVER_PORT $SERIAL_PORT
