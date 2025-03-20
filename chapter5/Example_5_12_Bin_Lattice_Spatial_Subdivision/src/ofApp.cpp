#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  resolution = 40;
  cols = floor(ofGetWidth() / resolution);
  rows = floor(ofGetHeight() / resolution);
  for (int i = 0; i < cols; ++i) {
    vector<vector<Boid *>> col;
    for (int j = 0; j < rows; ++j) {
      vector<Boid *> row;
      col.push_back(row);
    }
    grid.push_back(col);
  }

  flock.setup();
  for (int i = 0; i < 800; ++i) {
    Boid *boid = new Boid();
    boid->setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    flock.addBoid(boid);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      grid[i][j].clear();
    }
  }

  for (auto boid : flock.boids) {
    int col = floor(boid->position.x / resolution);
    int row = floor(boid->position.y / resolution);
    col = ofClamp(col, 0, cols - 1);
    row = ofClamp(row, 0, rows - 1);
    grid[col][row].push_back(boid);
  }

  flock.update(&grid, resolution);
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetLineWidth(1);
  ofSetColor(200);
  ofNoFill();

  for (int i = 0; i <= cols; ++i) {
    const int x = i * resolution;
    ofDrawLine(x, 0, x, ofGetHeight());
  }

  for (int j = 0; j <= rows; ++j) {
    const int y = j * resolution;
    ofDrawLine(0, y, ofGetWidth(), y);
  }

  const int mouseCol = floor(ofGetMouseX() / resolution);
  const int mouseRow = floor(ofGetMouseY() / resolution);
  ofSetColor(255, 50, 50, 100);
  ofFill();
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      const int col = mouseCol + i;
      const int row = mouseRow + j;
      if (col >= 0 && col < cols && row >= 0 && row < rows) {
        const int x = col * resolution;
        const int y = row * resolution;
        ofDrawRectangle(x, y, resolution, resolution);
      }
    }
  }

  flock.show();
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
void ofApp::mouseDragged(int x, int y, int button) {
  Boid *boid = new Boid();
  boid->setup(x, y);
  flock.addBoid(boid);
}

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
