#ifndef _SPRING
#define _SPRING

#include "Bob.h"
#include "ofMain.h"

class Spring {
public:
  void setup(float x, float y, float length);
  void connect(Bob *bob);
  void constrainLength(Bob *bob, float minLen, float maxLen);
  void show();
  void showLine(Bob *bob);

  ofVec2f anchor;
  float restLength;
  float k;
};

#endif
