#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { ofSetFrameRate(1); }

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  ofTranslate(ofGetWidth() * 0.5, ofGetHeight());
  ofSetLineWidth(2);
  ofSetColor(0);
  branch(80);
}

//--------------------------------------------------------------
void ofApp::branch(float length) {
  ofDrawLine(0, 0, 0, -length);
  ofTranslate(0, -length);

  length *= 0.67;

  if (length > 2) {
    int n = floor(ofRandom(1, 4));
    for (int i = 0; i < n; ++i) {
      float angle = ofRandom(-PI * 0.5, PI * 0.5);
      ofPushMatrix();
      ofRotateRad(angle);
      branch(length);
      ofPopMatrix();
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
