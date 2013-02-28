#!/bin/bash
# Modify with values in your environment

PORT=4444
SERIAL=/dev/cu.usbmodemfa131

while true ; do
	request=`(echo -e 'HTTP/1.1 200 OK\n\n'; cat index.html) |
            nc -l $PORT | grep  "^GET /" | cut -d " " -f 2`
	command=`expr $request : '^/cmd/\([A-z_]*\)'`
	if [[ $command ]]; then
		echo Sending command $command
		echo  $command > $SERIAL
	fi
done
