#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundAuto(false);
  ofBackground(255);

  generation = 0;
  w = 10;
  ruleset = {0, 1, 0, 1, 1, 0, 1, 0};

  const int cellsNum = floor(ofGetWidth() / w);
  for (int i = 0; i < cellsNum; ++i) {
    cells.push_back(0);
  }

  const int middleIndex = cells.size() / 2;
  cells[middleIndex] = 1;
}

//--------------------------------------------------------------
void ofApp::update() {
  if (generation * w > ofGetHeight())
    return;

  // skips first few frames (temporary fix to ensure first few lines are
  // rendered properly)
  if (ofGetFrameNum() > 8) {
    vector<int> tempCells = cells;
    for (int i = 1; i < cells.size() - 1; ++i) {
      const int left = tempCells[i - 1];
      const int me = tempCells[i];
      const int right = tempCells[i + 1];
      cells[i] = rules(left, me, right);
    }

    ++generation;
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  if (generation * w > ofGetHeight())
    return;

  for (int i = 1; i < cells.size() - 1; ++i) {
    if (cells[i] == 1) {
      ofFill();
      ofSetColor(0);
      const float x = i * w;
      const float y = generation * w;
      ofDrawRectangle(x, y, w, w);
    }
  }
}

//--------------------------------------------------------------
int ofApp::rules(int a, int b, int c) {
  const int index = a * 4 + b * 2 + c * 1;
  return ruleset[7 - index];
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
