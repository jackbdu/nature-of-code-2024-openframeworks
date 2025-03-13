#pragma once

#include "ofMain.h"

class Vehicle {
public:
  void setup(float x, float y);
  void applyBehaviors(vector<Vehicle *> vehicles);
  void applyForce(ofVec2f force);
  ofVec2f separate(vector<Vehicle *> vehicles);
  ofVec2f seek(ofVec2f target);
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
