/*
 * Peer Graded Assignment
 * 
 * Write a sketch that allows a user to access data in EEPROM using the Serial Monitor.
 * In the serial Monitor the user should be able to type one of two commands: "read and "write".
 * "Read" takes one argument, an EEPROM address. "Write" takes two arguments, an EEPROM address and a Value.
 * 
 * For example, if the user types "read 3" then the contents of the EEPROM address 3 should be printed to 
 * the serial monitor. IF the user types "write 3 10" then the value 10 should be written into address 3 of the EEPROM
 * 
 * Author: Richard Myrick T. Arellaga
 * Processor: Atmega 328P
 * Clock: 16MHz
*/

#include <EEPROM.h>

String cmd;
const String strReadcmd = "read";
const String strWritecmd = "write";

void setup() {
  
  Serial.begin(9600);
  
}

void loop() {

  if (Serial.available() > 0) {
    
    cmd = Serial.readStringUntil('\n'); 
   
    if (cmd.indexOf(strReadcmd,0)==0) {
      
      String addr = cmd.substring(5);
      int i_addr = addr.toInt();
      
      if (i_addr > 1023 || i_addr < 0) {
        Serial.println("Out of range, 0-1023 Only");
      }
      else { 
        int val = EEPROM.read(i_addr); 
        Serial.print("EEPROM Value at address ");
        Serial.print(i_addr);
        Serial.print("is ");
        Serial.println(val, DEC);
      }
    }

    if (cmd.indexOf(strWritecmd,0)==0) { 
            String temp = cmd;
            temp.remove(0, 6);
            int spaceBetween = temp.indexOf(' ');
      
            String destAddr = temp.substring(0, spaceBetween);
            int i_destAddr = destAddr.toInt(); 
      
            String strData = temp.substring(spaceBetween + 1); 
            int iData = strData.toInt(); 

      if (i_destAddr < 0 || i_destAddr > 1023 || iData < 0 || iData > 255) {
        
        Serial.println("Invalid, Address is 0-1023 Only, Data is from 0-255");
        
      }

      else { 
         Serial.print("Writing ");
         Serial.print(iData);
         Serial.print(" to");
         Serial.print(i_destAddr);
         
         EEPROM.write(i_destAddr,iData);
        
        Serial.println("Done!");
        
   }
  }
 }
}
