// תוכנית עם כפתור שמפעיל מנוע סרוו בזכות תקשורת 433
#include <VirtualWire.h>
const int tx_pin = 2;
const int indicate_pin = 13;
int pb1pin = 3;//pb1
int pb1val = 0;

void setup() {
  pinMode(pb1pin, INPUT);
  vw_set_tx_pin(tx_pin);
  pinMode(indicate_pin, OUTPUT);
  vw_setup(2000);
  digitalWrite(indicate_pin, HIGH);
}

void loop() {
  pb1val = digitalRead(pb1pin);
  /////////////////////PB1//////////////////////
  if (pb1val == HIGH) {
    digitalWrite(indicate_pin, HIGH);
    send("a");
  }

  if (pb1val == LOW) {
    digitalWrite(indicate_pin, LOW);
    send("b");
  }
}

void send (char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}
