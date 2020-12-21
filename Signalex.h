/*
  Signalex.h - Library for controlling signalex 7-segment flip diplays
  Using Clockboard by Keenan Rebera
  Created by Keenan Rebera April 6, 2020
*/

#ifndef Signalex_h
#define Signalex_h

#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MCP23017.h>

class Signalex {
    public:
        Signalex();
        Signalex(int address);
        void setup();
        void setSegmentOn(byte segment, bool value);
        void setSegmentOff(byte segment, bool value);
        void setAddress(int address);
    private:
        int pinForSegment(int pos, bool val);
        Adafruit_MCP23017 _mcp;
        unsigned char _address;
};

#endif