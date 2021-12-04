int led=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  //Serial.
}

void loop() {
  // put your main code here, to run repeatedly:
  int x=0;
  //Serial.println(led);
  for(x=0;x<255;x++)
  {
    analogWrite(led,x);
    delay(10);
  }
  
  for(x=255;x>0;x--)
  {
    analogWrite(led,x);
    delay(10);
  }
}
