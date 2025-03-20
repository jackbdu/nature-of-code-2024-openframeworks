#pragma once

#include "ofMain.h"

class Path {
public:
  void setup();
  void show();
  void drawThickLine(ofVec2f start, ofVec2f end, float lineWidth);

  float radius;
  ofVec2f start;
  ofVec2f end;
};
