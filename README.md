# Home-automation

Home automation using Raspberry PI 4B+ and 4 socket Relay module. 

Step 1 - 
Install Raspbian OS and update everything. 

Step 2 - 
Connect pins and sockets as per below - 
pin 1(+5V) - to VCC
pin 2(+3.3V) - to JDVCC
pin 34(Ground) - to GND relay
pin 31 - to IN1(switch 1 - light)
pin 32 - to IN2(switch 2 - fan)

Step 3 - 
connect live wire from mains 
Intercept light switch with IN1 in relay
intercept fan switch with IN2 in relay. 

Step 4 - 
Setup ADAFRUI.IO feed (private MQTT feed). 
create 3 feeds - room-light, room-fan, room.

Step 5 - 
Write Python program to receive from MQTT and control the GPIO pins in raspberry PI
program are in repo. 

Step 6 - 
Create IFTT account, link it to Google assitant. 

Step 7 - 
Create new applet as follows - 
Trigger - Google assistant Phrase
Action - Webhook
URL - https://io.adafruit.com/api/v2/Bluff/feeds/room-fan/data
Method - POST
Content - URL encoded
Body - X-AIO-Key=aio_TthI33he8iu1PHPmxSjKqC1l5STK&value=1

Change the URL feed name to the required feed name as per program.
Chnage body content "value" as per need and command. 

Step 8 - 
Add the 3 Python programs to services so that they start when PI board boots up. 

$sudo nano /etc/systemd/system/lights.service
$sudo systemctl start lights.service
If all is fine, 
$sudo enable lights.service

do the same for all 3 services.

<h6> All Ready to GO </h6>
Go to google asistant and command it !
