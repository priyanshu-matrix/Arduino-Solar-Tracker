#include <Servo.h>

Servo horizontalServo;  //Lower Motor
Servo verticalServo;    //Upper Motor

int horizontalPosition = 90;
int verticalPosition = 90;
int rotateSpeed = 3;
int upperMotorMax = 140;
int lowerMotorMax = 180;

int threshold = 50;

void setup() {
  horizontalServo.attach(2);
  verticalServo.attach(3);
  pinMode(8,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int bottomRight = analogRead(A0);
  int bottomLeft = analogRead(A1);
  int topLeft = analogRead(A2);
  int topRight = analogRead(A3);

  int avgTop = (topLeft + topRight) / 2;
  int avgBottom = (bottomLeft + bottomRight) / 2;
  int avgLeft = (topLeft + bottomLeft) / 2;
  int avgRight = (topRight + bottomRight) / 2;

  int previousHorizontal = horizontalPosition;
  int previousVertical = verticalPosition;

  if (abs(avgLeft - avgRight) > threshold) {
    if (avgLeft > avgRight) {
      horizontalPosition = constrain(horizontalPosition - rotateSpeed, 0, lowerMotorMax);
    } else {
      horizontalPosition = constrain(horizontalPosition + rotateSpeed, 0, lowerMotorMax);
    }
  }


  if (abs(avgTop - avgBottom) > threshold) {
    if (avgTop > avgBottom) {
      verticalPosition = constrain(verticalPosition + rotateSpeed, 0, upperMotorMax);
    } else {
      verticalPosition = constrain(verticalPosition - rotateSpeed, 0, upperMotorMax);
    }
  }
  digitalWrite(8,HIGH);
  while (previousHorizontal < horizontalPosition) {
    previousHorizontal++;
    horizontalServo.write(previousHorizontal);
    digitalWrite(8,LOW);

  }
  while (previousHorizontal > horizontalPosition) {
    previousHorizontal--;
    horizontalServo.write(previousHorizontal);
    digitalWrite(8,LOW);
  }

  while (previousVertical < verticalPosition) {
    previousVertical++;
    verticalServo.write(previousVertical);
    digitalWrite(8,LOW);
  }
  while (previousVertical > verticalPosition) {
    previousVertical--;
    verticalServo.write(previousVertical);
    digitalWrite(8,LOW);
  }

  Serial.print("LDR TL: ");
  Serial.print(topLeft);
  Serial.print(" | TR: ");
  Serial.print(topRight);
  Serial.print(" | BL: ");
  Serial.print(bottomLeft);
  Serial.print(" | BR: ");
  Serial.println(bottomRight);
  Serial.print("Horizontal Position: ");
  Serial.print(horizontalPosition);
  Serial.print(" | Vertical Position: ");
  Serial.println(verticalPosition);

  delay(0);  
}
