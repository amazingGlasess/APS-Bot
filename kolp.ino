//Rizqi Hidayat
//Ilyasa Sirojuddin
const int trigPin = 10;
const int echoPin = 13;
//relay
#define r1 A1
//motor 1
int In1 = 7;
int In2 = 8;
int ENA = 5;
//pump

// defines variables
long duration;
int distance;
//servo
#include <Servo.h>
Servo servo1;


void setup() {
//relay
pinMode(r1, OUTPUT);
//motor1
pinMode(In1,OUTPUT);
pinMode(In2,OUTPUT);
pinMode(ENA,OUTPUT);
//sensor
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

Serial.begin(9600); // Starts the serial communication
//pump

servo1.attach(9);
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);


// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;

//mulai IF
if (distance <= 5){ //Enter the Distance 

// Nyalain kipas
    digitalWrite(r1, HIGH);//NO=NYALA
    // Kasi Delay 2 detik
    delay(3000);

delay(500);
digitalWrite(In1,LOW);
 digitalWrite(In2,HIGH);
 analogWrite(ENA,220);
delay(500); 
 analogWrite(ENA,0);
//servo
servo1.write(180);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(0);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(180);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(0);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(180);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(0);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(180);
delay(1000);
servo1.write(90);
delay(1000);
servo1.write(0);
delay(1000);
servo1.write(90);
delay(1000);
//motor
digitalWrite(In1,LOW);
 digitalWrite(In2,HIGH);
 analogWrite(ENA,210);
delay(1200); 
 analogWrite(ENA,0);

 digitalWrite(r1, LOW);
    // Kasi Delay 2 detik
    delay(500);
 
 delay(4000);
 digitalWrite(In1,HIGH);
 digitalWrite(In2,LOW);
 analogWrite(ENA,230);
 delay(900);
}
else{
digitalWrite(In1,LOW);
 digitalWrite(In2,LOW);
 analogWrite(ENA,0);

}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(300);
}
