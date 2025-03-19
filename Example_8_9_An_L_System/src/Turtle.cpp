#include "Turtle.h"

void Turtle::setup(float _length, float _angle) {
  length = _length;
  angle = _angle;
};

void Turtle::render(string sentence) {
  ofSetColor(0);
  for (int i = 0; i < sentence.size(); ++i) {
    char c = sentence[i];
    if (c == 'F' || c == 'G') {
      ofDrawLine(0, 0, 0, -length);
      ofTranslate(0, -length);
    } else if (c == '+') {
      ofRotateRad(angle);
    } else if (c == '-') {
      ofRotateRad(-angle);
    } else if (c == '[') {
      ofPushMatrix();
    } else if (c == ']') {
      ofPopMatrix();
    }
  }
};
