//תוכנית אשר פועלת ברגע שלוחצים על כפתור אז הבאזר מפעיל צלילים של אזעקה
#define buzpin 8
#define pbpin 4
int pbval = 0;
void setup() {
pinMode(buzpin,OUTPUT);
pinMode(pbpin,INPUT);
tone(buzpin,3000,2000);
}
void loop() {
  pbval=digitalRead(pbpin);
  if(pbval==HIGH){
    tone(buzpin,7000,200);
    delay(200);
     tone(buzpin,3000,200);
    delay(200);
    tone(buzpin,7000,200);
    delay(200);
     tone(buzpin,3000,200);
    delay(200);
     tone(buzpin,7000,200);
    delay(200);
     tone(buzpin,3000,200);
    delay(200);
    tone(buzpin,7000,200);
    delay(200);
     tone(buzpin,3000,200);
    delay(200);
  }
  else{
    digitalWrite(buzpin,LOW);
  }
}
