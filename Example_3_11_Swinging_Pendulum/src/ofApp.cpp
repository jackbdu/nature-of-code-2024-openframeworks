#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { pendulum.setup(ofGetWidth() * 0.5, 0, 175); }

//--------------------------------------------------------------
void ofApp::update() {
  pendulum.update();
  pendulum.drag(ofGetMouseX(), ofGetMouseY());

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() { pendulum.show(); }

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
void ofApp::mousePressed(int x, int y, int button) { pendulum.clicked(x, y); }

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) { pendulum.stopDragging(); }

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
