<h1>Port to ESP 8266 - Node D1 mini V2<h1>

<h4> Pin out diag -</h4>

<img src = "https://i.pinimg.com/736x/65/22/fe/6522fe1f0ea1ec7503a2177503b52715.jpg">

<br>

In case of ESP 8266, only the following pins have pull up resistors - <br>
D3	IO, 10k Pull-up	GPIO0 <br>
D4	IO, 10k Pull-up, BUILTIN_LED	GPIO2 <br>

Using one for each Light and Fan. <br>
Code - my-duino.ino

<h4> Wiring Changes </h4>
5V to JDVCC (Relay)
3.3V to VCC (Relay)
G to GND (Relay)
d4 to IN1 (Relay)
D3 to IN2 (Relay)
