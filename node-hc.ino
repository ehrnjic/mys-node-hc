#define MY_DEBUG

#define MY_RADIO_RFM69
//#define MY_RFM69_NEW_DRIVER
#define MY_RFM69_FREQUENCY RFM69_433MHZ
#define MY_RFM69_TX_POWER_DBM 10
//#define MY_RFM69_ENABLE_ENCRYPTION
//#define MY_ENCRYPTION_SIMPLE_PASSWD "xxxxx"
#define MY_RFM69_NETWORKID 100
#define MY_PARENT_NODE_ID 254

#define MY_NODE_ID 101
#define CHILD_ID_0 0
#define CHILD_ID_1 1

#include <MySensors.h>  

//MyMessage msg(CHILD_ID_0,V_TRIPPED);

void setup() {
  //pinMode(3, INPUT_PULLUP);
  //pinMode(4, OUTPUT);
  Serial.print("Ready!\n");  
}

void presentation()  
{ 
  sendSketchInfo("Push button and 16 relays", "0.1");
  //present(CHILD_ID_0, S_BINARY);
  present(CHILD_ID_1, S_CUSTOM);
}

void loop() {  ///  uint8_t value;
//  static uint8_t sentValue=1;
  
  // Short delay to allow buttons to properly settle
//  sleep(5);

//  value = digitalRead(3);

//  if (value != sentValue) {
    // Value has changed from last transmission, send the updated value
//    send(msg.set(value==LOW));
//    sentValue = value;
//    Serial.println("Changed!");
//  }

  // Sleep until something happens with the sensor
//  sleep(1, CHANGE, 0);
}

void receive(const MyMessage &message) {
  Serial.print("Message received!\n");
  if (message.getType()==V_CUSTOM) {
    Serial.print("Incoming change for sensor:");
    Serial.print(message.getSensor());
    Serial.print(", New status: ");
    Serial.println(message.getUInt());
  }
}
