#include "Box.h"

void Box::setup(float _x, float _y) {
  x = _x;
  y = _y;
  w = 16;
};

void Box::show() {
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  ofDrawRectangle(x, y, w, w);

  ofNoFill();
  ofSetColor(0);
  ofDrawRectangle(x, y, w, w);
};
