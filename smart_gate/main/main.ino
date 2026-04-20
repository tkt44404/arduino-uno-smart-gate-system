#include <Servo.h>

#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define potPin A0
#define trig  13
#define echo 12
#define servoPin 9

Servo myServo;

int trigger_distance = 20; // max detectable object distance in cm
int servo_max_angle = 90;   // angle to hold when object is near
int servo_min_angle = 0;  // angle when no object is near
int number_displayed;
int time_delayed;
unsigned long openTime = 0;
bool servoOpen = false;



int pins[7] = {A,B,C,D,E,F,G};


void setup()
{ 
  pinMode(potPin, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.begin(9600);
}


bool digits[9][7] =      //An table to map segments(A-G) and numbers (1-9)
{
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};


void display_seven_segment(){
  int sensor_reading = analogRead(potPin);
  delay(5);
  number_displayed = map(sensor_reading, 0, 1023, 1, 9);//turns the analog input into values(1-9) 
  number_displayed = constrain(number_displayed, 1, 9); //locks range from 1-9
  time_delayed = number_displayed * 1000;
  
  for (int i = 0; i<7; i++){
    digitalWrite(pins[i],digits[number_displayed - 1][i]);
  }

}


long get_object_distance(){
  // Send trigger pulse 
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

  // Read echo
  long duration = pulseIn(echo,HIGH,30000);
  long distance = duration / 58; //scale to cm

  return distance;

}


void move_servo(){
  long distance = get_object_distance();

  // Move Servo if object is less than threshold in front of Sensor
  if (distance > 0 && distance < trigger_distance){
    myServo.write(servo_max_angle);
    openTime = millis();      // reset timer
    servoOpen = true;
  }

  // Object not detected check delay timer
  else if (servoOpen){
    if (millis() - openTime >= time_delayed){
      myServo.write(servo_min_angle);
      servoOpen = false;
    }
 }

}

void loop()
{
  //Display mode on 7-Segment Display
  display_seven_segment();

  //If an obeject is close move the servo
  move_servo();
  
}