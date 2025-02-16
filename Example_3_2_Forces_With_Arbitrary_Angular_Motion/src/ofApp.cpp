#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  for (int i = 0; i < 20; ++i) {
    Mover mover;
    mover.setup(ofRandomWidth(), ofRandomHeight(), ofRandom(0.1, 2));
    movers.push_back(mover);
  }
  attractor.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
  for (int i = 0; i < movers.size(); ++i) {
    const ofVec2f force = attractor.attract(movers[i]);
    movers[i].applyForce(force);

    movers[i].update();
  }

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  attractor.show();
  for (int i = 0; i < movers.size(); ++i) {
    movers[i].show();
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
