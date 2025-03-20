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

  if (ofRandom(1) < 0.025) {
    CustomShape shape;
    shape.setup(&box2d, ofGetWidth() * 0.5, 50);
    shapes.push_back(shape);
  }

  for (int i = shapes.size() - 1; i >= 0; --i) {
    if (shapes[i].checkEdge()) {
      shapes[i].removeBody();
      shapes.erase(shapes.begin() + i);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto shape : shapes) {
    shape.show();
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
