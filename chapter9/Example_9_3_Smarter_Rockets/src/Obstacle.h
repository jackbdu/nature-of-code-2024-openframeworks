#pragma once

#include "DNA.h"
#include "ofMain.h"

class Obstacle {
public:
  void setup(float x, float y, float width, float height);
  void show();
  bool contains(ofVec2f spot);

  ofVec2f position;
  float w;
  float h;
};
