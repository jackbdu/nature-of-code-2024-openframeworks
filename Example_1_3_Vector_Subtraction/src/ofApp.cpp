#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
  ofVec2f center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

  ofSetLineWidth(4);
  ofSetColor(200);
  ofDrawLine(0, 0, mouse.x, mouse.y);
  ofDrawLine(0, 0, center.x, center.y);

  mouse -= center;

  ofSetColor(0);
  ofTranslate(center.x, center.y);
  ofDrawLine(0, 0, mouse.x, mouse.y);
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
