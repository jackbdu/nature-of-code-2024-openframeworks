#pragma once

#include "FlowField.h"
#include "ofMain.h"

class Vehicle {
public:
  void setup(float x, float y, float _maxSpeed, float _maxForce);
  void follow(FlowField flow);
  void applyForce(ofVec2f force);
  void update();
  void borders();
  void show();

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float r;
  float maxSpeed;
  float maxForce;
};
