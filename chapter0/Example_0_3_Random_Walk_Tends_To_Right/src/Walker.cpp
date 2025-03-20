#include "Walker.h"

void Walker::setup() {
  x = ofGetWidth() * 0.5;
  y = ofGetHeight() * 0.5;
}

void Walker::show() {
  ofSetColor(0);
  ofDrawRectangle(x, y, 1, 1);
}

void Walker::step() {
  const float r = ofRandom(1);
  if (r < 0.4) {
    x++;
  } else if (r < 0.6) {
    x--;
  } else if (r < 0.8) {
    y++;
  } else {
    y--;
  }
  x = ofClamp(x, 0, ofGetWidth() - 1);
  y = ofClamp(y, 0, ofGetHeight() - 1);
}
