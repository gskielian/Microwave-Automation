#!/Library/Frameworks/Python.framework/Versions/2.7/bin/python

#I have a really long python path
#just use the " :r! which python " to add your path

import serial, time

#check on the bottom right corner of the Arduino IDE for the first argument of the next line
ser = serial.Serial('/dev/tty.usbmodem1411', 9600, timeout = 0.1)

def send_and_receive( theinput ):
    ser.write( theinput )
    while True:
      try:
        time.sleep(0.01)
        state = ser.readline()
        print state
        break
      except:
        pass
    time.sleep(0.1)

while True:

  input_var = input("Enter something: ")

  if input_var == 1:
    send_and_receive('1')
  elif input_var == 2:
    send_and_receive('2')
  else:
    time.sleep(0.1)



