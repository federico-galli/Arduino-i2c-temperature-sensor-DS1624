/* Example sketch for controlling the DS1624 ic with Arduino
   Tested with arduino-0022
   26/03/2010 Release 0.1
   Written by Federico and Riccardo Galli
   http://www.sideralis.org */

#include <DS1624.h>
#include <Wire.h>

/* Create an instance of the class
   0x48 is the address of the DS1624
   with three pin grounded. */
DS1624 temperature(0x48);

void setup() {  
  //Begin serial connection at 9600 baud
  Serial.begin(9600);
  //Start the continuous conversion of the temperature sensor
  temperature.start();
} 

void loop() {
  //Get the current temperature
  temperature.getTemp();
  //Print it
  delay(100);
  Serial.println(temperature.getTemp());
}
