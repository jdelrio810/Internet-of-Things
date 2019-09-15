import serial
import requests

arduino = serial.Serial('/dev/"nombre_dispositivo"', 115200)

# loop until manually stopped
# first flush possibly existing data in the input buffer:

arduino.flushInput()

while True:
    try:
        # read a single line from the serial interface represented by the ser object
        lineBytes = arduino.readline()
        # convert Bytes returned by the ser.readline() function to String
        line = lineBytes.decode('utf-8')
        # print the read line to the output
        print(line)
    
    except KeyboardInterrupt:
        break # stop the while loop
