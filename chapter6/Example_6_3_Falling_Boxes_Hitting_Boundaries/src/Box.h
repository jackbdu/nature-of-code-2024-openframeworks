#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Box {
public:
  void setup(ofxBox2d *box2d, float x, float y);
  void show();
  bool checkEdge();
  void removeBody();

  float w;
  float h;
  shared_ptr<ofxBox2dRect> shape;
};
