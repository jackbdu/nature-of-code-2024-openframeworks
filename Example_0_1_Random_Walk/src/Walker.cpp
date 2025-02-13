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
  const int choice = floor(ofRandom(4));
  if (choice == 0) {
    x++;
  } else if (choice == 1) {
    x--;
  } else if (choice == 2) {
    y++;
  } else {
    y--;
  }
}
