#pragma once

#include "ofMain.h"

class Path {
public:
  void setup();
  void addPoint(float x, float y);
  void show();
  void drawThickLine(ofVec2f start, ofVec2f end, float lineWidth);

  float radius;
  vector<ofVec2f> points;
};
