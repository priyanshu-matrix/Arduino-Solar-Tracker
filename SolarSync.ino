#include <Servo.h>  
Servo myServo;      
int ldrPin = A0;    
int servoPin = 9;   

void setup() {
  myServo.attach(servoPin);  
  Serial.begin(9600);        
}

void loop() {
  int ldrValue = analogRead(ldrPin);  
  
 
  int servoAngle = map(ldrValue, 0, 1023, 0, 180);

  
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" => Servo Angle: ");
  Serial.println(servoAngle);

  
  myServo.write(servoAngle);

  delay(50);  
}