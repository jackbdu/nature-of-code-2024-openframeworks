#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  total = 20;
  for (int i = 0; i < total; ++i) {
    randomCounts.push_back(0);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  const int index = floor(acceptreject() * randomCounts.size());
  ++randomCounts[index];
  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  const float w = ofGetWidth() / randomCounts.size();
  for (int x = 0; x < randomCounts.size(); ++x) {
    const float rectX = x * w;
    const float rectY = ofGetHeight() - randomCounts[x];
    const float rectW = w - 1;
    const float rectH = randomCounts[x];

    ofSetColor(127);
    ofFill();
    ofDrawRectangle(rectX, rectY, rectW, rectH);

    ofSetColor(0);
    ofSetLineWidth(2);
    ofNoFill();
    ofDrawRectangle(rectX, rectY, rectW, rectH);
  }
}

float ofApp::acceptreject() {
  while (true) {
    const float r1 = ofRandom(1);
    const float probability = r1;
    const float r2 = ofRandom(1);

    if (r2 < probability) {
      return r1;
    }
  }
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
