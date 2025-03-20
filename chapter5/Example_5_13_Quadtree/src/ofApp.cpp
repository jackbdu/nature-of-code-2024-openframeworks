#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  Rectangle boundary;
  boundary.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.5, ofGetWidth(),
                 ofGetHeight());
  qtree.setup(boundary, 8);
  for (int i = 0; i < 2000; ++i) {
    int x = ofRandomNormal(ofGetWidth() * 0.5, ofGetWidth() * 0.125);
    int y = ofRandomNormal(ofGetHeight() * 0.5, ofGetHeight() * 0.125);
    MyPoint p;
    p.setup(x, y);
    qtree.insert(p);
  }
}

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  qtree.show();

  Rectangle range;
  range.setup(ofGetMouseX(), ofGetMouseY(), 50, 50);

  ofSetRectMode(OF_RECTMODE_CENTER);
  if (ofGetMouseX() < ofGetWidth() && ofGetMouseY() < ofGetHeight()) {
    ofSetColor(255, 50, 50, 50);
    ofFill();
    ofDrawRectangle(range.x, range.y, range.w * 2, range.h * 2);

    ofSetLineWidth(2);
    ofSetColor(255, 50, 50);
    ofNoFill();
    ofDrawRectangle(range.x, range.y, range.w * 2, range.h * 2);

    vector<MyPoint> points = qtree.query(range);
    ofSetColor(50, 50, 50);
    ofFill();
    for (auto p : points) {
      ofDrawCircle(p.x, p.y, 1.5);
    }
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
