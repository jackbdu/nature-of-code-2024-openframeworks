#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  img.load("texture.png");
  emitter.setup(0, 75, img);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(0);

  for (int i = 0; i < 3; ++i) {
    emitter.addParticle();
  }

  const float dx = ofMap(ofGetMouseX(), 0, ofGetWidth(), -0.2, 0.2);
  wind = ofVec2f(dx, 0);
  emitter.applyForce(wind);

  emitter.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

  emitter.show();

  drawVector(wind, ofVec2f(0, -50), 500);
}

//--------------------------------------------------------------
void ofApp::drawVector(ofVec2f vector, ofVec2f position, float scale) {
  const float arrowSize = 4;
  const float length = vector.length() * scale;

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(vector.angleRad(ofVec2f(1, 0)));

  ofSetColor(255);
  ofDrawLine(0, 0, length, 0);
  ofDrawLine(length, 0, length - arrowSize, +arrowSize * 0.5);
  ofDrawLine(length, 0, length - arrowSize, -arrowSize * 0.5);

  ofPopMatrix();
}

//--------------------------------------------------------------
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
