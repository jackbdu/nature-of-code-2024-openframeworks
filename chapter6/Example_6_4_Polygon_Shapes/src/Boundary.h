#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Boundary {
public:
  void setup(ofxBox2d *box2d, float _x, float _y, float _w, float _h);
  void show();

  float x;
  float y;
  float w;
  float h;
  shared_ptr<ofxBox2dRect> shape;
};
