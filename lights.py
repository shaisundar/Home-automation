import sys
import RPi.GPIO as GPIO
import time

# Import Adafruit IO MQTT client.
from Adafruit_IO import MQTTClient

# set GPIO connection
GPIO.setmode(GPIO.BOARD)
GPIO.setup(31, GPIO.OUT)
GPIO.output(31, GPIO.HIGH)

# Set to your Adafruit IO key.
# Remember, your key is a secret,
# so make sure not to publish it when you publish this code!
ADAFRUIT_IO_KEY = 'aio_TthI33he8iu1PHPmxSjKqC1l5STK'

# Set to your Adafruit IO username.
# (go to https://accounts.adafruit.com to find your username)
