#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  box2d.init();
  box2d.setGravity(0, 10);

  Boundary boundaryA, boundaryB;
  boundaryA.setup(&box2d, ofGetWidth() * 0.25, ofGetHeight() - 5,
                  ofGetWidth() * 0.5 - 50, 10);
  boundaryB.setup(&box2d, ofGetWidth() * 0.75, ofGetHeight() - 50,
                  ofGetWidth() * 0.5 - 50, 10);
  boundaries.push_back(boundaryA);
  boundaries.push_back(boundaryB);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  box2d.update();

  if (ofRandom(1) < 0.1) {
    Box box;
    box.setup(&box2d, ofGetWidth() * 0.5, 50);
    boxes.push_back(box);
  }

  for (int i = boxes.size() - 1; i >= 0; --i) {
    if (boxes[i].checkEdge()) {
      boxes[i].removeBody();
      boxes.erase(boxes.begin() + i);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto box : boxes) {
    box.show();
  }

  for (auto boundary : boundaries) {
    boundary.show();
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
