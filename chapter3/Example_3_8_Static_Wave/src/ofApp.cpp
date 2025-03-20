#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  angleVelocity = 0.2;
  amplitude = 100;
}

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  angle = 0;
  for (int x = 0; x <= ofGetWidth(); x += 24) {
    const float y = amplitude * sin(angle) + ofGetHeight() * 0.5;

    ofSetLineWidth(2);

    ofFill();
    ofSetColor(127, 127);
    ofDrawCircle(x, y, 24);

    ofNoFill();
    ofSetColor(0);
    ofDrawCircle(x, y, 24);

    angle += angleVelocity;
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
