//data => D11

#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2
const int ledPin = 13;
bool ledOn = false;

// Singleton instance of the radio driver
RH_ASK driver;

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, SERVER_ADDRESS);

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  if (!manager.init())
    Serial.println("init failed");
}

uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];

void loop()
{
  if (manager.available())
  {
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (manager.recvfrom(buf, &len, &from))
    {
      digitalWrite(ledPin, ledOn ? HIGH : LOW);
      ledOn = !ledOn;
      Serial.print("got request from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
  }
}

