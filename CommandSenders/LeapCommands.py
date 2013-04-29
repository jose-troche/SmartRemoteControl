################################################################################
# Copyright (C) 2012-2013 Leap Motion, Inc. All rights reserved.               #
################################################################################

# export PYTHONPATH=<LeapDir>/LeapSDK/lib
# or in Windows:
# set PYTHONPATH=<LeapDir>\LeapSDK\lib;<LeapDir>\LeapSDK\lib\x64
# So that python can find the Leap module
import Leap, sys, requests


class LeapListener(Leap.Listener):
    # Timestamp of last frame processed
    last_timestamp = None

    # Process frames every time_resolution microsecs
    time_resolution = 1000000 * 1.5

    # Url where commands are sent
    ARDUINO_SERVER_URL = 'http://localhost:4444/cmd/'

    def on_frame(self, controller):
        # Get the most recent frame
        frame = controller.frame()

        # Process frames at time_resolution rate
        if self.last_timestamp and (
           frame.timestamp - self.last_timestamp < self.time_resolution):
            return
        else:
            self.last_timestamp = frame.timestamp

        if not frame.hands.empty:
            # Get the first hand
            hand = frame.hands[0]

            # Get the hand's pitch and roll angles
            roll  = hand.palm_normal.roll * Leap.RAD_TO_DEG
            pitch = hand.direction.pitch * Leap.RAD_TO_DEG

            print "Hand roll: %.0f degrees, pitch %.0f degrees, " % (roll, pitch)

            if abs(-35-roll) < 5: # right
                self.send_command('tv_vol_up')

            if abs(35-roll) < 5:  # left
                self.send_command('tv_vol_down')

            if abs(35-pitch) < 5: # pointing up
                self.send_command('tv_vol_up')

            if abs(-20-pitch) < 5:  # pointing down
                self.send_command('tv_vol_down')

    def send_command(self, cmd):
        "Sends a command to Arduino Web Server"
        print "Sending command ", cmd
        requests.get(self.ARDUINO_SERVER_URL + cmd)


def main():
    # Create a listener and controller
    listener = LeapListener()
    controller = Leap.Controller()

    # Have the listener receive events from the controller
    controller.add_listener(listener)

    # Keep this process running until Enter is pressed
    print "Press Enter to quit..."
    sys.stdin.readline()

    # Remove the listener when done
    controller.remove_listener(listener)


if __name__ == "__main__":
    main()
