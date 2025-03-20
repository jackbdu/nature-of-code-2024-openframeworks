#pragma once

#include "ofMain.h"

class Boid {
public:
  void setup(float x, float y);
  void applyForce(ofVec2f force);
  void flock(vector<Boid *> *boids);
  void update(vector<vector<vector<Boid *>>> *grid, float resolution);
  void show();
  void borders();
  ofVec2f seek(ofVec2f target);
  ofVec2f separate(vector<Boid *> *boids);
  ofVec2f align(vector<Boid *> *boids);
  ofVec2f cohere(vector<Boid *> *boids);

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float r;
  float maxSpeed;
  float maxForce;
};
