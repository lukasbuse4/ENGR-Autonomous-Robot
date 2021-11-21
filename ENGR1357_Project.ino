

#include <Servo.h>
void navigate_maze();
int find_hole();
void speed_changer(int);
void side_speed_changer(int);
void reset_pos(int);

Servo front_right_wheel;

#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 8 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
//  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
//  Serial.println("with Arduino UNO R3");


  


void setup() 
{
  // put your setup code here, to run once:
  front_right_wheel.attach();
  navigate_maze();
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
}


void navigate_maze()
{
  int drive_back = find_hole();
  reset(drive_back);
  drive_back = find_hole();
  reset(drive_back);
  
  
}


int find_hole()
{
  int delay_cntr;
  side_speed_changer(88);
  //set wheels to a certain speed(needs to be slow, 90 being no movement)
  while(true)
  {
      // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    delay(5);
    delay_cntr += 5;
    if(distance > 10)
    {
      side_speed_changer(90);
      //set speed to 0;
      break;
    }
  }
  //drive forward
  return delay_cntr;
}

void speed_changer(int spd)
{
  //sets speed based on passed in value
  //depending on how the wheels are set up the value might
  //have to be inverse on one side, need to come up with logic for that
  //probably something like - int inverse_spd = -1*(180 - spd);
  
}

void side_speed_changer(int spd)
{
  //set middle wheel to whatever speed is passed in
}

void reset_pos(int drive_back)
{
  speed_changer(92);
  delay(drive_back);
  return;
}
