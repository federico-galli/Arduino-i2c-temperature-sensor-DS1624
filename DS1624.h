/*
  Library for controlling the DS1624 ic with Arduino
  Tested with arduino-0018
  26/03/2010 Release 0.1
  Written by Federico and Riccardo Galli
  http://www.sideralis.org
*/

#ifndef DS1624_h
#define DS1624_h
#include "WProgram.h"
#include <Wire.h>

#define CONTINUOUS_CONVERSION 0x00
#define CONVERT_T 0xEE
#define READ_T 0xAA

class DS1624
{
  int8_t addr;
  public:
    DS1624(int8_t addr);
    void start();
    float getTemp();
    //private:
    //;
};

#endif
