//UniRxを使ってシリアル通信

byte x = 0;
byte y= 0;
byte z = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
x++;
z--;

Serial.println(x);
Serial.println(",");
Serial.println(y);
Serial.println(",");
Serial.println(z);
Serial.println("\r\n");
}
