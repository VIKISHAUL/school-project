#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;
const int receive_pin = 3;
const int ledpin = 8;

int pos = 0;
void setup() {
  vw_set_rx_pin(receive_pin);
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  if (vw_get_message(message, &messageLength)) {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      char c = message[i];
      Serial.print(c);

      if (c == 'a') {
        analogWrite(ledpin , 225);
        delay(100);
      }

      if (c == 'b') {
        digitalWrite(ledpin , LOW);
        delay(100);
      }
    }
    Serial.println();
  }

}
