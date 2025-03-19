#pragma once

#include "ofMain.h"

class Cell {
public:
  void setup(int _state, float _x, float _y, float _w);
  void show();

  int state;
  int previous;
  float x;
  float y;
  float w;
};
