#include "Walker.h"

void Walker::setup() {
  tx = 0;
  ty = 10000;
}

void Walker::show() {
  const float r = 24;

  ofSetColor(127);
  ofFill();
  ofDrawCircle(x, y, r);

  ofSetColor(0);
  ofNoFill();
  ofSetLineWidth(2);
  ofDrawCircle(x, y, r);
}

void Walker::step() {
  x = ofMap(ofNoise(tx), 0, 1, 0, ofGetWidth());
  y = ofMap(ofNoise(ty), 0, 1, 0, ofGetHeight());

  tx += 0.01;
  ty += 0.01;
}
