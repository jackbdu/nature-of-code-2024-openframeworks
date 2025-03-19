#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { ofSetCircleResolution(100); }

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  drawCircles(ofGetWidth() * 0.5, ofGetHeight() * 0.5, ofGetWidth() * 0.5);
}

//--------------------------------------------------------------
void ofApp::drawCircles(float x, float y, float r) {
  ofSetLineWidth(2);
  ofSetColor(0);
  ofNoFill();
  ofDrawCircle(x, y, r);

  if (r > 4) {
    r *= 0.75;
    drawCircles(x, y, r);
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
