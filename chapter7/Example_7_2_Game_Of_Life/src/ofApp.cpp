#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  w = 8;
  columns = ofGetWidth() / w;
  rows = ofGetHeight() / w;
  board = create2DVector(columns, rows);
  for (int i = 1; i < columns - 1; ++i) {
    for (int j = 1; j < rows - 1; ++j) {
      board[i][j] = floor(ofRandom(2));
    }
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  vector<vector<int>> tempBoard = board;

  for (int i = 1; i < columns - 1; ++i) {
    for (int j = 1; j < rows - 1; ++j) {
      int neighborSum = 0;
      for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
          neighborSum += tempBoard[i + k][j + l];
        }
      }

      neighborSum -= tempBoard[i][j];

      if (tempBoard[i][j] == 1 && neighborSum < 2)
        board[i][j] = 0;
      else if (tempBoard[i][j] == 1 && neighborSum > 3)
        board[i][j] = 0;
      else if (tempBoard[i][j] == 0 && neighborSum == 3)
        board[i][j] = 1;
      else
        board[i][j] = tempBoard[i][j];
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < rows; ++j) {
      const float x = i * w;
      const float y = j * w;

      ofSetColor(255 - board[i][j] * 255);
      ofFill();
      ofDrawRectangle(x, y, w, w);

      ofSetColor(0);
      ofNoFill();
      ofDrawRectangle(x, y, w, w);
    }
  }
}

//--------------------------------------------------------------
vector<vector<int>> ofApp::create2DVector(int columns, int rows) {
  vector<vector<int>> vec;
  for (int i = 0; i < columns; ++i) {
    vector<int> column;
    for (int j = 0; j < rows; ++j) {
      column.push_back(0);
    }
    vec.push_back(column);
  }

  return vec;
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
