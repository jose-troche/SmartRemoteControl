################################################################################
# Send commands received via Emotiv EPOC device
################################################################################
import sys, requests

# Url where commands are sent
ARDUINO_SERVER_URL = 'http://localhost:4444/cmd/'

def send_command(cmd):
    "Sends a command to Arduino Web Server"
    print "Sending command ", cmd
    #requests.get(ARDUINO_SERVER_URL + cmd)


if __name__ == "__main__":
    # Keep running until q or Ctrl+C
    print "Receiving commands... (q to quit)"
    while True:
        c = sys.stdin.readline().strip().lower()
        if c == 'q':
            break
        elif c == 'u':
            send_command('tv_vol_up')
        elif c == 'd':
            send_command('tv_vol_down')
        elif c == 'h':
            send_command('tv_tv')
