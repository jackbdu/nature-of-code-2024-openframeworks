#pragma once

#include "ofMain.h"

class FlowField {
public:
  void setup(float _resolution);
  void init();
  void show();
  ofVec2f lookup(ofVec2f position);

  float resolution;
  int cols;
  int rows;
  vector<vector<ofVec2f>> field;
};
