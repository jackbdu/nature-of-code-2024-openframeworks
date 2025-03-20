#include "Cell.h"

void Cell::setup(int _state, float _x, float _y, float _w) {
  state = _state;
  previous = state;

  x = _x;
  y = _y;
  w = _w;
};

void Cell::show() {
  ofFill();
  if (previous == 0 && state == 1) {
    ofSetColor(0, 0, 255);
  } else if (state == 1) {
    ofSetColor(0);
  } else if (previous == 1 && state == 0) {
    ofSetColor(255, 0, 0);
  } else {
    ofSetColor(255);
  }
  ofDrawRectangle(x, y, w, w);

  ofNoFill();
  ofSetColor(0);
  ofDrawRectangle(x, y, w, w);
};
