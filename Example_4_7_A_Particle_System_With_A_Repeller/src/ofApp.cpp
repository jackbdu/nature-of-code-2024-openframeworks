#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  emitter.setup(ofGetWidth() * 0.5, 60);
  repeller.setup(ofGetWidth() * 0.5, 250);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  emitter.addParticle();

  ofVec2f gravity = ofVec2f(0, 0.1);
  emitter.applyForce(gravity);

  emitter.applyRepeller(repeller);

  emitter.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  emitter.show();
  repeller.show();
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
