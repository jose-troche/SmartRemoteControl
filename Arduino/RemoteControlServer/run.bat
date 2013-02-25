@echo off
cd /d %0\..
rem Please set the path where arduino is installed
set ARDUINO_PATH=c:\arduino-1.0.3
set JAVA=%ARDUINO_PATH%\java\bin\java
set RXTX=%ARDUINO_PATH%\lib\RXTXcomm.jar
rem RXTX_LIB_PATH is where the rxtxSerial.dll is located
set RXTX_LIB_PATH=%ARDUINO_PATH%
set SERVER_PORT=80
set SERIAL_PORT=COM4
echo Control+C to stop server
echo.
%JAVA% -cp .;%RXTX% -Djava.library.path=%RXTX_LIB_PATH% arduino.RemoteControlServer %SERVER_PORT% %SERIAL_PORT%
