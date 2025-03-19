#pragma once

#include "ofMain.h"

class KochLine {
public:
  void setup(ofVec2f _start, ofVec2f _end);
  void show();
  vector<ofVec2f> kochPoints();

  ofVec2f start;
  ofVec2f end;
};
