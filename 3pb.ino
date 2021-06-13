#define pb1 3
int pbvalue1 = 0;
#define pb2 4
int pbvalue2 = 0;
#define pb3 5
int pbvalue3 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pb1, INPUT);
  pinMode(pb2, INPUT);
  pinMode(pb3, INPUT);
}

void loop() {
  pbvalue1 = digitalRead(pb1);
  pbvalue2 = digitalRead(pb2);
  pbvalue3 = digitalRead(pb3);
  Serial.print("pb1 = ");
  Serial.println(pbvalue1);
  Serial.print("pb2 = ");
  Serial.println(pbvalue2);
  Serial.print("pb3 = ");
  Serial.println(pbvalue3);
  Serial.println("___________________");
  delay(600);
}
