/*
 * Peer Graded Assignment
 * 
 * Build a circuit that lights an LED when it is sufficiently
 * dark in a room. Demonstrate the circuit by covering the
 * photoresistor to simulate darkness.
 * 
 * Author: Richard Myrick T. Arellaga
 * Processor: Atmega 328P
 * Clock: 16MHz
*/

const int thresh = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  

}

void loop() {
 
 int x = analogRead(0);

 if(x > thresh){
   digitalWrite(6,HIGH);
 }else{
   digitalWrite(6,LOW);
 }

}
