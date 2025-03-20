#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofVec2f start = ofVec2f(0, 200);
  ofVec2f end = ofVec2f(ofGetWidth(), 200);

  KochLine segment;
  segment.setup(start, end);
  segments.push_back(segment);

  for (int i = 0; i < 5; ++i) {
    generate();
  }
}

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto segment : segments) {
    segment.show();
  }
}

//--------------------------------------------------------------
void ofApp::generate() {
  vector<KochLine> next;

  for (auto segment : segments) {
    vector<ofVec2f> points = segment.kochPoints();
    for (int i = 0; i <= points.size() - 2; ++i) {
      ofVec2f a = points[i];
      ofVec2f b = points[i + 1];
      KochLine line;
      line.setup(a, b);
      next.push_back(line);
    }
  }

  segments.clear();
  segments = next;
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
