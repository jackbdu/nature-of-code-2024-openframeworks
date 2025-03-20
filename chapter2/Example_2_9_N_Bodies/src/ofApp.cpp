#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  for (int i = 0; i < 10; ++i) {
    Body body;
    body.setup(ofRandomWidth(), ofRandomHeight(), ofRandom(0.1, 2));
    bodies.push_back(body);
  }
}

//--------------------------------------------------------------
void ofApp::update() {

  for (int i = 0; i < bodies.size(); ++i) {
    for (int j = 0; j < bodies.size(); ++j) {
      if (i != j) {
        const ofVec2f force = bodies[j].attract(bodies[i]);
        bodies[i].applyForce(force);
      }
    }
    bodies[i].update();
  }

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int i = 0; i < bodies.size(); ++i) {
    bodies[i].show();
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
