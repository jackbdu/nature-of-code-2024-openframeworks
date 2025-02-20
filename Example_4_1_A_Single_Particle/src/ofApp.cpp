#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  particle.setup(ofGetWidth() * 0.5, 10);
  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update() {
  const ofVec2f gravity = ofVec2f(0, 0.1);
  particle.applyForce(gravity);

  if (particle.isDead()) {
    particle = Particle();
    particle.setup(ofGetWidth() * 0.5, 10);
    ofLog() << "Particle dead!";
  }

  particle.update();

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() { particle.show(); }

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
