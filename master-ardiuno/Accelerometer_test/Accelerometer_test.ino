void setup() {
  Serial.begin(9600);
}
 
void loop() {

  float x =0;
  float y = 0;
  float z = 0;

  for(int i=0;i<100;i++)
  {
    x+=analogRead(A0);
    y+=analogRead(A1);
    z+=analogRead(A2);
    }
    x=x/100.0;
    y=y/100.0;
    z=z/100.0;

  Serial.print(" X:");
  Serial.print(x);
  Serial.print(" Y:");
  Serial.print(y);
  Serial.print(" Z:");
  Serial.println(z);
 
  delay(1000);
}
