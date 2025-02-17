#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  amplitude = 200;
  angle = 0;
  angleVelocity = 0.05;
}

//--------------------------------------------------------------
void ofApp::update() {
  x = amplitude * sin(angle);
  angle += angleVelocity;

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

  ofSetLineWidth(2);
  ofSetColor(0);
  ofDrawLine(0, 0, x, 0);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(x, 0, 24);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(x, 0, 24);
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
