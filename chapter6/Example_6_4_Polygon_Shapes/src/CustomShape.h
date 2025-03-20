#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class CustomShape {
public:
  void setup(ofxBox2d *box2d, float x, float y);
  void show();
  bool checkEdge();
  void removeBody();

  ofPolyline polyline;
  shared_ptr<ofxBox2dPolygon> shape;
};
