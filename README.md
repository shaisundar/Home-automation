# Home-automation

<h3>Home automation using Raspberry PI 4B+ and 4 socket Relay module.</h3> 

Step 1 - <br>
Install Raspbian OS and update everything. <br>

Step 2 - <br>
Connect pins and sockets as per below - <br>
pin 1(+5V) - to VCC<br>
pin 2(+3.3V) - to JDVCC<br>
pin 34(Ground) - to GND relay<br>
pin 31 - to IN1(switch 1 - light)<br>
pin 32 - to IN2(switch 2 - fan)<br>

Step 3 - <br>
connect live wire from mains <br>
Intercept light switch with IN1 in relay<br>
intercept fan switch with IN2 in relay. <br>

Step 4 - <br>
Setup ADAFRUI.IO feed (private MQTT feed). <br>
create 3 feeds - room-light, room-fan, room.<br>

Step 5 - <br>
Write Python program to receive from MQTT and control the GPIO pins in raspberry PI<br>
program are in repo. <br>

Step 6 - <br>
Create IFTT account, link it to Google assitant. <br>

Step 7 - <br>
Create new applet as follows - <br>
Trigger - Google assistant Phrase<br>
Action - Webhook<br>
URL - https://io.adafruit.com/api/v2/Bluff/feeds/room-fan/data<br>
Method - POST<br>
Content - URL encoded<br>
Body - X-AIO-Key=aio_TthI33he8iu1PHPmxSjKqC1l5STK&value=1<br>

Change the URL feed name to the required feed name as per program.<br>
Chnage body content "value" as per need and command. <br>

Step 8 - <br>
Add the 3 Python programs to services so that they start when PI board boots up. <br>

$sudo nano /lib/systemd/system/lights.service<br>
$sudo systemctl start lights.service<br>
If all is fine, <br>
$sudo enable lights.service<br>

do the same for all 3 services.<br>

<h4> All Ready to GO
Go to google asistant and command it !</h4>
