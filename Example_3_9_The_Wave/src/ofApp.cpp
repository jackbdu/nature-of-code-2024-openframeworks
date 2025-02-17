#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  startAngle = 0;
  angleVelocity = 0.2;
}

//--------------------------------------------------------------
void ofApp::update() {
  angle = startAngle;
  startAngle += 0.02;
  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int x = 0; x <= ofGetWidth(); x += 24) {
    const float y = ofMap(sin(angle), -1, 1, 0, ofGetHeight());

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
