#include "Boundary.h"

void Boundary::setup(ofxBox2d *box2d, float _x, float _y, float _w, float _h) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;

  shape = make_shared<ofxBox2dRect>();
  shape->setFriction(0.2);
  shape->setup(box2d->getWorld(), x, y, w, h);
};

void Boundary::show() {
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  ofDrawRectangle(x, y, w, h);

  ofNoFill();
  ofSetColor(0);
  ofDrawRectangle(x, y, w, h);
};
