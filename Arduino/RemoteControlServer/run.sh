#!/bin/bash
# Modify with values in your environment

PORT=4444
SERIAL=/dev/cu.usbmodemfa131
stty -f $SERIAL gfmt1:cflag=38b00:iflag=10:lflag=0:oflag=0:discard=f:dsusp=19:eof=4:eol=ff:eol2=ff:erase=7f:intr=3:kill=15:lnext=16:min=0:quit=1c:reprint=12:start=11:status=14:stop=13:susp=1a:time=0:werase=17:ispeed=9600:ospeed=9600

finally () {
    echo Exit
    rm response
    exit
}

trap finally SIGINT

echo Listening on port $PORT and sending commands to serial port $SERIAL. Ctrl+C to stop
mkfifo response
while true; do    
    cat response | nc -l $PORT | (
        read line
        command=`echo $line | cut -d" " -f2`
        if [[ $command == '/' ]]; then
            (echo -e 'HTTP/1.1 200 OK\n'; cat index.html) > response
            echo Sent index.html
        else
            command=`expr $command : '/cmd/\([A-z_]*\)'`
            if [[ $command ]]; then
                echo $command> $SERIAL
                #echo Executed $command > response
                echo 'HTTP/1.1 204 No Content' > response
                echo Executed $command
            else
                echo "" > response
            fi
        fi
    )
done