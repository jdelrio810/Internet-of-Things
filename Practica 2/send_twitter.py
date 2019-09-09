import requests


url = "https://api.thingspeak.com/apps/thingtweet/1/statuses/update"
data = Archivo.json


resp =requests.post(url,json=data)
print("Mensaje Enviado")
