#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  x = 100;
  y = 100;
  xspeed = 2.5;
  yspeed = 2;
}

//--------------------------------------------------------------
void ofApp::update() {
  x = x + xspeed;
  y = y + yspeed;

  if (x > ofGetWidth() || x < 0) {
    xspeed = xspeed * -1;
  }
  if (y > ofGetHeight() || y < 0) {
    yspeed = yspeed * -1;
  }

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  const float r = 24;

  ofSetColor(127);
  ofFill();
  ofDrawCircle(x, y, r);

  ofSetColor(0);
  ofSetLineWidth(2);
  ofNoFill();
  ofDrawCircle(x, y, r);
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
