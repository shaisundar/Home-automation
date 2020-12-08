#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>


#define WLAN_SSID       "SlowPoke"
#define WLAN_PASS       "Prithikakaka"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Bluff"
#define AIO_KEY         "key-here"

static const uint8_t D1   = 5;
static const uint8_t D5   = 14;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;

#define LED 2 
int LIGHT = D3;
int FAN = D4;

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe lightfeed = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/room-light");
Adafruit_MQTT_Subscribe fanfeed = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/room-fan");
void MQTT_connect();

void setup()
{ 
  //pinMode(LED,OUTPUT);
  pinMode(LIGHT,OUTPUT);
  pinMode(FAN,OUTPUT);
  
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address

  mqtt.subscribe(&lightfeed);
  mqtt.subscribe(&fanfeed);
}


void loop() {
   MQTT_connect();
   Adafruit_MQTT_Subscribe *subscription;
   while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &lightfeed) {
      //Serial.print(F("Got: "));
      //Serial.println((char *)lightfeed.lastread);
      if(strcmp((char *)lightfeed.lastread,"0")){
        //digitalWrite(LED, HIGH);
        digitalWrite(LIGHT, LOW);
      }
      if(strcmp((char *)lightfeed.lastread,"1")){
        //digitalWrite(LED, LOW);
        digitalWrite(LIGHT, HIGH);
      }
    }

    if (subscription == &fanfeed) {
      //Serial.print(F("Got: "));
      //Serial.println((char *)lightfeed.lastread);
      if(strcmp((char *)fanfeed.lastread,"0")){
        //digitalWrite(LED, HIGH);
        digitalWrite(FAN, LOW);
      }
      if(strcmp((char *)fanfeed.lastread,"1")){
        //digitalWrite(LED, LOW);
        digitalWrite(FAN, HIGH);
      }
    }
  }
}


void MQTT_connect() {
  int8_t ret;
 
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
 
  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
