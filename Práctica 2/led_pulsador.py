import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup (23,GPIO.IN)
GPIO.setup (24,GPIO.OUT)

while True:
    GPIO.output (24,GPIO.LOW)
    value=GPIO.input(23)
    
    if value == True:
        
        GPIO.output (24,GPIO.HIGH)
        time.sleep(30)

    else:

        GPIO.output (24,GPIO.LOW)
