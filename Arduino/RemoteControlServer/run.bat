@echo off
cd /d %0\..
set SERVER_PORT=80
set SERIAL_PORT=COM4
echo Control+C to stop server
echo.
java arduino.RemoteControlServer %SERVER_PORT% %SERIAL_PORT%
pause
