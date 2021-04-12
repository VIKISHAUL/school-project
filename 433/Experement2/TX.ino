#include <VirtualWire.h>
const int tx_pin = 2;
const int indicate_pin = 13;

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
  if (potval>0 && potval<341) {
    digitalWrite(indicate_pin, LOW);
    Serial.print("potval = ");
    Serial.println(potval);
    send("a");
  }
if (potval>341 && potval<682){
   digitalWrite(indicate_pin, LOW);
   Serial.print("potval = ");
    Serial.println(potval);
    send("b");
  }
if (potval<682 && potval<1023){
digitalWrite(indicate_pin, LOW);
   Serial.print("potval = ");
    Serial.println(potval);
    send("c");
  }
  else {
   digitalWrite(indicate_pin, HIGH);
   Serial.print("potval = ");
   Serial.println(potval);
   send("e");
}
}
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}
