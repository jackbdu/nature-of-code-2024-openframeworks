#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { ofSetCircleResolution(100); }

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  drawCircles(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 320);
}

//--------------------------------------------------------------
void ofApp::drawCircles(float x, float y, float radius) {
  ofSetColor(0);
  ofNoFill();
  ofDrawCircle(x, y, radius);

  if (radius > 16) {
    drawCircles(x + radius * 0.5, y, radius * 0.5);
    drawCircles(x - radius * 0.5, y, radius * 0.5);
    drawCircles(x, y + radius * 0.5, radius * 0.5);
    drawCircles(x, y - radius * 0.5, radius * 0.5);
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
