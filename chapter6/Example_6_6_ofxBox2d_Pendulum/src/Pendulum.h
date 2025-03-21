#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Pendulum {
public:
  void setup(ofxBox2d *box2d, float x, float y, float _len);
  void show();

  float r;
  float len;
  shared_ptr<ofxBox2dCircle> anchor;
  shared_ptr<ofxBox2dCircle> bob;
  shared_ptr<ofxBox2dJoint> arm;
};
