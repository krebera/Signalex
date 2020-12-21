#include "Arduino.h"
#include "Signalex.h"

Signalex::Signalex(int address) : _address(address) { }

Signalex::Signalex(){
  _address = 0;
}

void Signalex::setup() {
    this->_mcp.begin(_address);
    for(int i = 0; i < 16; ++i) {
        this->_mcp.pinMode(i, OUTPUT);
    }
}

void Signalex::setAddress(int address){
  _address = address;
}

int Signalex::pinForSegment(int pos, bool active) {
  switch(pos) {
    case 0:
      return (active ? 8 : 2);
      break;
    case 1:
      return (active ? 9 : 3);
      break;
    case 2:
      return (active ? 10 : 4);
      break;
    case 3:
      return (active ? 14 : 6);
      break;
    case 4:
      return (active ? 13 : 5);
      break;
    case 5:
      return (active ? 12 : 0);
      break;
    case 6:
      return (active ? 11 : 1);
      break;
    default:
      return 7; //Unused [as is 15]
  }
}

void Signalex::setSegmentOn(byte segment, bool value) {
    int thisPin = pinForSegment(segment, value);
    _mcp.digitalWrite(thisPin, HIGH);
}

void Signalex::setSegmentOff(byte segment, bool value) {
    int thisPin = pinForSegment(segment, value);
    _mcp.digitalWrite(thisPin, LOW);
}
