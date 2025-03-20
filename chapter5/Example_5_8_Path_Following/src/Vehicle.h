#pragma once

#include "Path.h"
#include "ofMain.h"

class Vehicle {
public:
  void setup(float x, float y, float _maxSpeed = 4, float _maxForce = 0.1);
  void follow(Path path);
  void applyForce(ofVec2f force);
  void seek(ofVec2f target);
  void update();
  void borders(Path path);
  void show(Path path, bool debug);
  ofVec2f getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b);

  ofVec2f future;
  ofVec2f normal;
  ofVec2f target;
  bool hasTarget;
  float worldRecord;

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float r;
  float maxSpeed;
  float maxForce;
};
