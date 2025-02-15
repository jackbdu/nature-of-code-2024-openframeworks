#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { mover.setup(ofGetWidth() * 0.5, 30, 5); }

//--------------------------------------------------------------
void ofApp::update() {
  const ofVec2f gravity = ofVec2f(0, 1);
  mover.applyForce(gravity);

  if (ofGetMousePressed()) {
    const ofVec2f wind = ofVec2f(0.5, 0);
    mover.applyForce(wind);
  }

  if (mover.contactEdge()) {
    const float c = 0.1;
    ofVec2f friction = mover.velocity;
    friction *= -1;
    friction.scale(c);

    mover.applyForce(friction);
  }

  mover.bounceEdges();
  mover.update();

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() { mover.show(); }

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
