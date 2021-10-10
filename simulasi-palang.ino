#include <Servo.h>
Servo servo;
int angle = 9;

// nomor pin
const int trigPin = 10;
const int echoPin = 11;
// variabel
long duration;
int distance;

void setup() {
  servo.attach(8);
  servo.write(angle);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);
delay(1000);

if(distance<20)
{
  servo.write(180);
  }
  else
  {
    servo.write(70);
    }
}
