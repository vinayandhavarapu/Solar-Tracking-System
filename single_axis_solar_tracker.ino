#include <EEPROM.h>
#include <Servo.h>
Servo myservo;
int sensor1=A1;
int sensor2=A0 ;
int val1;
int val2; 
int pos=0;
int error;
int state; 
void setup() 
{
  Serial.begin(9600);
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT);
myservo.attach(9);
}
void loop() 
{
myservo.attach(9);
val1=analogRead(sensor1);
val2=analogRead(sensor2);
if (val1-val2>4) 
{
  myservo.write(pos); 
  pos=pos-1; 
  delay(10);
}
else if (val2-val1>4) 
{
  myservo.write(pos);
  pos=pos+1;
  delay(10);
}
else 
{
  myservo.write(pos);
}
 
if (pos>90) 
{
  pos=90;
}
else if (pos<0) 
{
  pos=0;
}
  Serial.println(pos);
  
}