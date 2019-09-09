import smtplib
from email.mime.text import MIMEText


msg = MIMEText("Mensaje")
server = smtplib.SMTP('servidor de correo',#Puerto)
server.starttls()
server.login('mail@gmail.com','contraseña')
msg['Subject'] = "Asunto"
server.sendmail("mail origen","mail destino",msg.as_string())
print("Email enviado")
server.quit()
