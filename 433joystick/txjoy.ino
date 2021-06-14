// תוכנית עם כפתור שמפעיל מנוע סרוו בזכות תקשורת 433
#include <VirtualWire.h>
const int tx_pin = 2;
const int indicate_pin = 13;
int pb1pin = 3;//pb1
int pb1val = 0;


#define Xin A0
#define buttonpin 4

int buttonVal = 0;
int xVal = 0;

void setup() {
  pinMode(buttonpin, INPUT);
  pinMode(Xin, INPUT);
  Serial.begin(9600);

  pinMode(pb1pin, INPUT);
  vw_set_tx_pin(tx_pin);
  pinMode(indicate_pin, OUTPUT);
  vw_setup(2000);
  digitalWrite(indicate_pin, HIGH);
}

void loop() {
  xVal = analogRead(Xin);
  buttonVal = digitalRead(buttonpin);

  Serial.print("X Val = ");
  Serial.println(xVal);
  Serial.print("Button Val = ");
  Serial.println(buttonVal);
  Serial.println("_");

  pb1val = digitalRead(pb1pin);
  /////////////////////PB1//////////////////////
 

   if (xVal <= 500) {
    send("c");
    Serial.println("Left was sent");
  }
  if (500 < xVal and xVal < 560) {
    send("d");
    Serial.println("Middle was sent");
  }
  if (560 <= xVal) {
    send("e");
    Serial.println("Right was sent");
  }
  Serial.println("=========");
  delay(800);
}

void send (char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}
