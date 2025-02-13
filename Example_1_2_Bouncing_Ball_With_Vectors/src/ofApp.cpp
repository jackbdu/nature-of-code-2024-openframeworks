#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  position = ofVec2f(100, 100);
  velocity = ofVec2f(2.5, 2);
}

//--------------------------------------------------------------
void ofApp::update() {

  position += velocity;

  if (position.x > ofGetWidth() || position.x < 0) {
    velocity.x = velocity.x * -1;
  }
  if (position.y > ofGetHeight() || position.y < 0) {
    velocity.y = velocity.y * -1;
  }

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  const float r = 24;

  ofSetColor(127);
  ofFill();
  ofDrawCircle(position.x, position.y, r);

  ofSetColor(0);
  ofSetLineWidth(2);
  ofNoFill();
  ofDrawCircle(position.x, position.y, r);
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
