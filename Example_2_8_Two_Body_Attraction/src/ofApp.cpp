#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  bodyA.setup(320, 40);
  bodyB.setup(320, 200);
  bodyA.velocity = ofVec2f(1, 0);
  bodyB.velocity = ofVec2f(-1, 0);
}

//--------------------------------------------------------------
void ofApp::update() {
  bodyA.attract(&bodyB);
  bodyB.attract(&bodyA);

  bodyA.update();
  bodyB.update();

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  bodyA.show();
  bodyB.show();
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
