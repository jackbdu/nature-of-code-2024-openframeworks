#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  debug = true;
  offset = 25;

  vehicle.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  vehicle.boundaries(offset);
  vehicle.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetLineWidth(2);

  if (debug) {
    ofSetColor(0);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(ofGetWidth() * 0.5, ofGetHeight() * 0.5,
                    ofGetWidth() - offset * 2, ofGetHeight() - offset * 2);
  }

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
void ofApp::mousePressed(int x, int y, int button) { debug = !debug; }

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
