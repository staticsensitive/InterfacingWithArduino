/*
 * Peer Graded Assignment
 * Build a circuit that contains two push buttons, an LED
 * and any other basic components that you think you need.
 * The LED should turn on when either the first button or 
 * the second button is presed. Only use your Arduino for
 * power and ground.
 * 
 * Author: Richard Myrick T. Arellaga
 * Processor: Atmega 328P
 * Clock: 16MHz
*/
void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);

}

void loop() {
  digitalWrite(6,LOW);

  if(!(digitalRead(8)) || (!digitalRead(7)))
  {
    digitalWrite(6,HIGH);
  }

}
