// data => D12

#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Singleton instance of the radio driver
RH_ASK driver;

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, CLIENT_ADDRESS);

void setup() 
{
  Serial.begin(9600);
  if (!manager.init())
    Serial.println("init failed");
}

uint8_t data[] = "Hello World!";
// Dont put this on the stack:
uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];

void loop()
{
  Serial.println("Sending to ask_reliable_datagram_server");
    
  // Send a message to manager_server
  if (!manager.sendto(data, sizeof(data), SERVER_ADDRESS))
  {
  }
    Serial.println("sendtoWait failed");
  delay(500);
}

