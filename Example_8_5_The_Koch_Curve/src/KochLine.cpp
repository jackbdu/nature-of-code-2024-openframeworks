#include "KochLine.h"

void KochLine::setup(ofVec2f _start, ofVec2f _end) {
  start = _start;
  end = _end;
};

void KochLine::show() {
  ofSetLineWidth(2);

  ofNoFill();
  ofSetColor(0);

  ofDrawLine(start.x, start.y, end.x, end.y);
};

vector<ofVec2f> KochLine::kochPoints() {
  ofVec2f a = start;
  ofVec2f e = end;

  ofVec2f v = end - start;
  v /= 3;
  ofVec2f b = a + v;
  ofVec2f d = b + v;

  v.rotateRad(-PI / 3);
  ofVec2f c = b + v;

  return {a, b, c, d, e};
}
