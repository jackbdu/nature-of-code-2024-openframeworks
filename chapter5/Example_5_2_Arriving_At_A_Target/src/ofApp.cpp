#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { vehicle.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.5); }

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());

  vehicle.arrive(mouse);
  vehicle.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetLineWidth(2);

  ofSetColor(127);
  ofFill();
  ofDrawCircle(mouse.x, mouse.y, 24);

  ofSetColor(0);
  ofNoFill();
  ofDrawCircle(mouse.x, mouse.y, 24);

  vehicle.show();
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
