//Servo Begin
#include <Servo.h>

Servo servo;  //Make a way to call the servo
//ServoEnd
//Ultrasonic Begin
int trigPin = 8;    //Trig - green Jumper
int echoPin = 7;    //Echo - yellow Jumper
long duration, cm, inches;
//Ultrasonic End
void setup() {
  // put your setup code here, to run once:
  //Ultrasonic Begin
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Ultrasonic End
  //Servo Begin
  servo.attach(3);  //Setup a servo on PWM 3
  //Servo End
}

void loop() {
  // put your main code here, to run repeatedly:
  //Ultrasonic Begin
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  //Ultrasonic End
  //Servo Begin
   if (cm >= 26)
   {
    right();//Call function to move right at EOF
    Serial.println(cm);
   }
   else if (cm <= 25)
   {
    left();//Call function to move left at EOF
    Serial.println(cm);
   }
   else
   {
    Serial.println(cm);
   }
  Serial.print(inches);
  Serial.print(" inches, or ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  
  delay(250);
  
}
void left(){
  servo.write(544);
}
void right(){
  servo.write(2400);
}
