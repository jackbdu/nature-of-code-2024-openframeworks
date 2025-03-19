#pragma once

#include "ofMain.h"

class Turtle {
public:
  void setup(float _length, float _angle);
  void render(string sentence);

  float length;
  float angle;
};
