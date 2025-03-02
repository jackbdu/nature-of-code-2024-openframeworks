#include "FlowField.h"

void FlowField::setup(float _resolution) {
  resolution = _resolution;
  cols = ofGetWidth() / resolution;
  rows = ofGetHeight() / resolution;
  field.assign(cols, vector<ofVec2f>());
  for (int i = 0; i < cols; ++i) {
    field[i].assign(rows, ofVec2f());
  }
  init();
}

void FlowField::init() {
  const float noiseOffset = ofRandom(10000);
  float xoff = 0;
  for (int i = 0; i < cols; ++i) {
    float yoff = 0;
    for (int j = 0; j < rows; ++j) {
      const float angle =
          ofMap(ofNoise(xoff, yoff, noiseOffset), 0, 1, 0, TWO_PI);
      field[i][j] = ofVec2f(1, 0).rotateRad(angle);
      yoff += 0.1;
    }
    xoff += 0.1;
  }
}

void FlowField::show() {
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      const float w = ofGetWidth() / float(cols);
      const float h = ofGetHeight() / float(rows);
      ofVec2f v = field[i][j];
      v.scale(w * 0.5);
      const float x = i * w + w / 2;
      const float y = j * h + h / 2;
      ofSetLineWidth(1);
      ofDrawLine(x, y, x + v.x, y + v.y);
    }
  }
}

ofVec2f FlowField::lookup(ofVec2f position) {
  const int column = ofClamp(floor(position.x / resolution), 0, cols - 1);
  const int row = ofClamp(floor(position.y / resolution), 0, rows - 1);
  return field[column][row];
}
