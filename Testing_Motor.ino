// This file works.
// Connect the board to both your computer and the circuit
// Open in Arduino IDE as it is easiest to upload onto the board from there
// Press save then Upload to board, should be second button in top left.
// After uploading to board please reset board
// Turn power on in the circuit and watch the magic happen

#include <Servo.h>

Servo motor1;
Servo motor2;

void setup() 
{
  // put your setup code here, to run once:
  motor1.attach(3);
  motor2.attach(4);
  //motor1.write(70);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  motor1.write(60);
  motor2.write(120);
  delay(5000);
  motor1.write(90);
  delay(2000);
  motor1.write(120);
  motor2.write(60);
  delay(5000);
  motor1.write(90);
  delay(2000);
  
//}
}
