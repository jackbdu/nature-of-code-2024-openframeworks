#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  spring.setup(ofGetWidth() * 0.5, 10, 100);
  bob.setup(ofGetWidth() * 0.5, 100);
}

//--------------------------------------------------------------
void ofApp::update() {
  const ofVec2f gravity = ofVec2f(0, 2);
  bob.applyForce(gravity);

  bob.update();
  bob.handleDrag(ofGetMouseX(), ofGetMouseY());

  spring.connect(&bob);

  spring.constrainLength(&bob, 30, 200);

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  spring.showLine(&bob);
  bob.show();
  spring.show();
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
void ofApp::mousePressed(int x, int y, int button) { bob.handleClick(x, y); }

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) { bob.stopDragging(); }

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
