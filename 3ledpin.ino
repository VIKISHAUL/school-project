#define greenled 7
#define redled 8
#define yellowled 9
void setup() {
pinMode(greenled,OUTPUT);
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
}

void loop() {
digitalWrite(greenled,HIGH);
digitalWrite(redled,HIGH);
digitalWrite(yellowled,HIGH);
delay(500);
digitalWrite(greenled,LOW);
digitalWrite(redled,LOW);
digitalWrite(yellowled,LOW);
delay(500);
}
