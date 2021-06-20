//תוכנית עם כפתור שמפעיל מנועע סרוו להרמת משטח מתרומם בזכות מערכת תקשורת 433
#include <VirtualWire.h>
#include "ServoTimer2.h"
 
ServoTimer2 myservo;
int pos = 0;
 
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;
const int receive_pin = 3;
 
void setup() {


  
  vw_set_rx_pin(receive_pin);
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_setup(2000);
  vw_rx_start();
 
  myservo.attach(9);
}
 
void loop() {
  if (vw_get_message(message, &messageLength)) {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++) {
      char c = message[i];
      Serial.println(c);
      if (c == 'a') {
        myservo.write(map(124,0,180,544,2400));
      }
      if (c == 'b') {
        myservo.write(map(94,0,180,544,2400));
        
      }
    }
  }
}
