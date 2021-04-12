#include <VirtualWire.h>
#include <Servo.h>
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;
const int receive_pin = 3;
const int ledpin = 8;
int pos = 0;
Servo myservo;

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(receive_pin);
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_setup(2000);
  vw_rx_start();
  pinMode(ledpin, OUTPUT);
  myservo.attach(9);
}

void loop() {
  if (vw_get_message(message, &messageLength)) {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      char c = message[i];
      Serial.print(c);

      if (c == 'a') {
        digitalWrite(ledpin , LOW);
        myservo.write(45);
        delay(100);
      }

      if (c == 'b') {
        digitalWrite(ledpin , HIGH);
        myservo.write(90);
        delay(100);
      }
      if (c == 'c') {
        digitalWrite(ledpin , LOW);
        myservo.write(135);
        delay(100);
      }
      Serial.println();
    }
  }
}
