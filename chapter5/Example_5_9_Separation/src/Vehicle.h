#pragma once

#include "ofMain.h"

class Vehicle {
public:
  void setup(float x, float y);
  void applyForce(ofVec2f force);
  void separate(vector<Vehicle *> vehicles);
  void update();
  void show();
  void borders();

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float r;
  float maxSpeed;
  float maxForce;
};
