#include <Servo.h>


Servo horizontalServo;
Servo verticalServo;


int ldrTopLeft = A0;
int ldrTopRight = A1;
int ldrBottomLeft = A2;
int ldrBottomRight = A3;


int horizontalServoPin = 9;
int verticalServoPin = 10;


int threshold = 50;  
int horizontalPosition = 90;  
int verticalPosition = 90;    

void setup() {
  
  horizontalServo.attach(horizontalServoPin);
  verticalServo.attach(verticalServoPin);

  
  horizontalServo.write(horizontalPosition);
  verticalServo.write(verticalPosition);
  
  Serial.begin(9600);  
}

void loop() {
  
  int topLeft = analogRead(ldrTopLeft);
  int topRight = analogRead(ldrTopRight);
  int bottomLeft = analogRead(ldrBottomLeft);
  int bottomRight = analogRead(ldrBottomRight);
  
  
  int avgTop = (topLeft + topRight) / 2;
  int avgBottom = (bottomLeft + bottomRight) / 2;
  int avgLeft = (topLeft + bottomLeft) / 2;
  int avgRight = (topRight + bottomRight) / 2;

  
  if (abs(avgLeft - avgRight) > threshold) {  
      horizontalPosition = constrain(horizontalPosition - 1, 0, 180);  
    } else {
      horizontalPosition = constrain(horizontalPosition + 1, 0, 180); 
    }
  }

  
  if (abs(avgTop - avgBottom) > threshold) {  
    if (avgTop > avgBottom) {
      verticalPosition = constrain(verticalPosition + 1, 0, 180);  
    } else {
      verticalPosition = constrain(verticalPosition - 1, 0, 180);  
    }
  }

  
  horizontalServo.write(horizontalPosition);
  verticalServo.write(verticalPosition);

 
  Serial.print("LDR TL: "); Serial.print(topLeft);
  Serial.print(" | TR: "); Serial.print(topRight);
  Serial.print(" | BL: "); Serial.print(bottomLeft);
  Serial.print(" | BR: "); Serial.println(bottomRight);
  Serial.print("Horizontal Position: "); Serial.print(horizontalPosition);
  Serial.print(" | Vertical Position: "); Serial.println(verticalPosition);

  delay(1000);  
}
