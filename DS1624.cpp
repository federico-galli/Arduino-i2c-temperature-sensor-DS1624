/*
  Library for controlling the DS1624 ic with Arduino
  Tested with arduino-0018
  26/03/2010 Release 0.1
  Written by Federico and Riccardo Galli
  http://www.sideralis.org
*/

#include "WProgram.h"
#include "DS1624.h"
#include <Wire.h>

DS1624::DS1624(int8_t addr)
{
  this->addr=addr;
  Wire.begin();
}

void DS1624::start()
{
    Wire.beginTransmission(this->addr);
    Wire.send(0xAC);
    Wire.send(CONTINUOUS_CONVERSION); //Put the DS1624 in continuos conversion mode
    Wire.endTransmission();
    delay (100); //Min time needed to store the previous command is 10ms
    Wire.beginTransmission(this->addr);
    Wire.send(CONVERT_T); //Enable the continuos conversion mode
    Wire.endTransmission();
}

float DS1624::getTemp()
{
  float temperature = 0;
  int tempmsb = 0;
  int templsb = 0;
  int temp2 = 0;

  Wire.beginTransmission(this->addr);
  Wire.send(READ_T);
  Wire.requestFrom(this->addr, 2);

  if (Wire.available()) {
    tempmsb = Wire.receive();
  }
  if (Wire.available()) {
    templsb = Wire.receive();
  }
  temp2 = templsb >> 3;
  temperature = (float(tempmsb) + (float(temp2) * 0.03125));
  Wire.endTransmission();
  return temperature;
}
