#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  w = 8;
  columns = ofGetWidth() / w;
  rows = ofGetHeight() / w;
  board = create2DVector(columns, rows);
  for (int i = 1; i < columns - 1; ++i) {
    for (int j = 1; j < rows - 1; ++j) {
      Cell cell;
      cell.setup(floor(ofRandom(2)), i * w, j * w, w);
      board[i][j] = cell;
    }
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  for (int x = 1; x < columns - 1; ++x) {
    for (int y = 1; y < rows - 1; ++y) {
      int neighborSum = 0;
      for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
          neighborSum += board[x + i][y + j].previous;
        }
      }

      neighborSum -= board[x][y].previous;

      if (board[x][y].previous == 1 && neighborSum < 2)
        board[x][y].state = 0;
      else if (board[x][y].previous == 1 && neighborSum > 3)
        board[x][y].state = 0;
      else if (board[x][y].previous == 0 && neighborSum == 3)
        board[x][y].state = 1;
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < rows; ++j) {
      board[i][j].show();
      board[i][j].previous = board[i][j].state;
    }
  }
}

//--------------------------------------------------------------
vector<vector<Cell>> ofApp::create2DVector(int columns, int rows) {
  vector<vector<Cell>> vec;
  for (int i = 0; i < columns; ++i) {
    vector<Cell> column;
    for (int j = 0; j < rows; ++j) {
      Cell cell;
      cell.setup(0, i * w, j * w, w);
      column.push_back(cell);
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
