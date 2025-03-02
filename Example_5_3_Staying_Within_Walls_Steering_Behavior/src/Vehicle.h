#pragma once

#include "ofMain.h"

class Vehicle {
public:
  void setup(float x, float y);
  void update();
  void applyForce(ofVec2f force);
  void boundaries(float offset);
  void show();

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float r;
  float maxSpeed;
  float maxForce;
};
