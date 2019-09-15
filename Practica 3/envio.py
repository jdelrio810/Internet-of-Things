import serial
import time

arduino = serial.Serial('/dev/nombre del dispositivo', 115200)
arduino.flushInput()

while True:
	try:
		arduino=serial.Serial('/dev/nombre del dispositivo',baudrate=115200, timeout = 1.0)
		inputPin = input("escribe una letra: ")
		inputPinBytes = inputPin.encode('utf-8')
		arduino.write(inputPinBytes)
		time.sleep(0.1)
		arduino.close()
		
	except KeyboardInterrupt:
		break # stop the while loop
