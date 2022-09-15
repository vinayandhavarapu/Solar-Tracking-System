Active Solar Trackers Consists of Two Types they are Single Axis Solar Tracker and Double Axis Solar Tracker
Here I am going to demonstrate these two trackers using Arduino Uno

**Single Axis Solar Tracker**

The Solar Panel Tracker is designed to follow the sun movement so that maximum light intensity hits on the solar panel, thus increasing the power efficiency.

In this system, the whole solar panel moves from east to west in a day to point in the direction of the sun. The use of a solar tracker circuit in the field of energy production will increase its efficiency. This system can also be successfully implemented in other solar energy-based projects like water heaters and steam turbines.

 **Components Required:**

                            Arduino Uno Board

                            Servo Motor SG90

                            Resistors 10K – 3 Nos

                            LDR – 2 Nos

                            Breadboard

                            Connecting Wires

                            5 to 12 Volt power Supply
                            
                            
**Working of the Project:**

Two LDR’s (Light Dependent Resistor) LDR1 & LDR2 are connected to Analog pins of the Arduino. A solar plate is attached in parallel to the axis of the servo motor and both the sensors are kept on the solar plate as shown in the figure above.

The design & the arrangement is done in such a manner that the movement of the sun is from LDR1 to LDR2, as shown in the image below.


There are three cases that are to be followed:-

![image](https://user-images.githubusercontent.com/70559104/190326946-b7125663-abe0-413d-b771-4e822bc462a8.png)

Note: Put a Blockage between the 2 LDR by keeping it at distance of at least 5 cm.

**Case 1: Sun is in the left side**
Light on LDR1 is high because the shadow of barrier falls on LDR2 so solar plate moves clockwise.

**Case 2: Sun is in right Side**
Light on LDR2 is high because the shadow of barrier falls on LDR1 so solar plate movie anticlockwise.

**Case 3: Sun is in the Center**
Light on both LDR’s is equal so, plate will not rotate in any direction.

**Circuit Connections:**

![Screenshot (74)](https://user-images.githubusercontent.com/70559104/190328306-37433226-1c60-4123-b8d8-31cbc15ba33d.png)


**Source Code:**

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

References:

https://how2electronics.com/arduino-based-solar-tracker-using-ldr-servo-motor/

https://www.solarreviews.com/blog/are-solar-axis-trackers-worth-the-additional-investment
