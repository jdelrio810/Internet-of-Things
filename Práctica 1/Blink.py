import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup (PIN,GPIO.OUT)


while True:
    GPIO.output(PIN,True)
    time.sleep(1)
    GPIO.output(PIN,False)
    time.sleep(1)
