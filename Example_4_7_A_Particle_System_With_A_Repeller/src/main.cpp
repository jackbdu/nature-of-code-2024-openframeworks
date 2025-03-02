/*
 * Code example for The Nature of Code (2024 Edition)
 * (https://natureofcode.com/)
 * Ported from p5.js by Jack B. Du
 * (https://github.com/jackbdu/nature-of-code-2024-openframeworks)
 */

#include "ofApp.h"
#include "ofMain.h"

//========================================================================
int main() {

  // https://github.com/openframeworks/openFrameworks/issues/6828
  ofGLFWWindowSettings settings;
  settings.doubleBuffering = false;
  settings.setSize(640, 240);
  settings.windowMode = OF_WINDOW; // can also be OF_FULLSCREEN

  auto window = ofCreateWindow(settings);

  ofRunApp(window, make_shared<ofApp>());
  ofRunMainLoop();
}
