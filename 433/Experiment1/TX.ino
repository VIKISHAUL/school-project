#include <VirtualWire.h> //תוכנית עם מערכת תקשורת אשר משדרת
const int tx_pin = 2; //RX
const int indicate_pin = 13; //

#define potpin A0
int potval = 0;
void setup() {
  Serial.begin(9600);
  pinMode(potpin, INPUT);
  vw_set_tx_pin(tx_pin);
  pinMode(indicate_pin, OUTPUT);
  vw_setup(2000);
}

void loop() {
  potval = analogRead(potpin);
  if (potval <= 500) {
    digitalWrite(indicate_pin, LOW);
    Serial.print("potval = ");
    Serial.println(potval);
    send("a");
  }
  else {
    digitalWrite(indicate_pin, HIGH);
    Serial.print("potval = ");
    Serial.println(potval);
    send("b");
  }
}
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}
