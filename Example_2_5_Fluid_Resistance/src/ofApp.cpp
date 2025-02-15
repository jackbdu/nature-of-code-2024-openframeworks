#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  reset();
  liquid.setup(0, ofGetHeight() * 0.5, ofGetWidth(), ofGetHeight() * 0.5, 0.1);
}

//--------------------------------------------------------------
void ofApp::update() {

  for (int i = 0; i < movers.size(); ++i) {
    if (liquid.contains(movers[i])) {
      const ofVec2f dragForce = liquid.calculateDrag(movers[i]);
      movers[i].applyForce(dragForce);
    }

    const ofVec2f gravity = ofVec2f(0, 0.1 * movers[i].mass);
    movers[i].applyForce(gravity);

    movers[i].update();
    movers[i].checkEdges();
  }

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  liquid.show();

  for (int i = 0; i < movers.size(); ++i) {
    movers[i].show();
  }
}

//--------------------------------------------------------------
void ofApp::reset() {
  for (int i = 0; i < 9; ++i) {
    Mover mover;
    mover.setup(40 + i * 70, 0, ofRandom(0.5, 3));
    movers.push_back(mover);
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
