#include "Particle.h"

void Particle::setup(float x, float y) {
  position = ofVec2f(x, y);
  const float vx = ofRandomGaussian(0.0, 0.3);
  const float vy = ofRandomGaussian(-1.0, 0.3);
  velocity = ofVec2f(vx, vy);
  acceleration = ofVec2f(0, 0);
  lifespan = 100;

  img.load("texture.png");
  fbo.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
}

void Particle::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;

  lifespan -= 2;
}

void Particle::show() {
  fbo.begin();
  ofClear(0);
  ofDisableBlendMode();
  img.draw(0, 0);
  ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
  ofSetColor(0, 255 - lifespan);
  ofDrawRectangle(0, 0, img.getWidth(), img.getHeight());
  fbo.end();

  fbo.setAnchorPercent(0.5, 0.5);
  fbo.draw(position.x, position.y);
}

void Particle::applyForce(ofVec2f force) { acceleration += force; }

bool Particle::isDead() { return lifespan < 0; }
