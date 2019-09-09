import RPi.GPIO as GPIO                    
import time                                
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)                     

TRIG = 23                                  #pin 23 como TRIG
ECHO = 24                                  #pin 24 como ECHO
V    = 34300                               # Velocidad del sonido 34300cm/s 

print ("Medicion de la distancia en curso")
GPIO.setup(TRIG,GPIO.OUT)                  #TRIG como salida
GPIO.setup(ECHO,GPIO.IN)                   #ECHO como entrada

GPIO.output(TRIG, False)                   #TRIG en estado bajo
print ("Espere que el sensor se estabilice")
time.sleep(2)                              #Esperar 2 segundos

while True:
    
    GPIO.output(TRIG, True)                    #TRIG en estado alto
    time.sleep(0.00001)                        #Delay de 0.00001 segundos
    GPIO.output(TRIG, False)                   #TRIG en estado bajo


    while GPIO.input(ECHO)==0:                 #Comprueba si ECHO está en estado bajo
        pulse_start = time.time()                #Guarda el tiempo transcurrido, mientras esta en estado bajo

    while GPIO.input(ECHO)==1:                 #Comprueba si ECHO está en estado alto
        pulse_end = time.time()                  #Guarda el tiempo transcurrido, mientras esta en estado alto

  #COMPLETAR UNA PARTE DEL CODIGO

    if distancia > 2 and distancia < 400:      #Comprueba si la distancia está dentro del rango
        print ("Distancia: ",distancia,"cm")       #Imprime la distancia 
    else:
        print ("Fuera de Rango")                  #Imprime fuera de rango
    time.sleep(2)
