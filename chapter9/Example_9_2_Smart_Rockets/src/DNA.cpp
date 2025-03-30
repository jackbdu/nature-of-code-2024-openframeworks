#include "DNA.h"

void DNA::setup(int lifeSpan) {
  maxForce = 0.1;
  for (int i = 0; i < lifeSpan; ++i) {
    const float angle = ofRandom(TWO_PI);
    ofVec2f gene = ofVec2f(1, 0).rotateRad(angle);
    gene *= ofRandom(maxForce);
    genes.push_back(gene);
  }
};

shared_ptr<DNA> DNA::crossover(shared_ptr<DNA> partner) {
  shared_ptr<DNA> child = make_shared<DNA>();
  child->setup(genes.size());

  int midpoint = floor(ofRandom(genes.size()));

  for (int i = 0; i < genes.size(); ++i) {
    if (i < midpoint) {
      child->genes[i] = genes[i];
    } else {
      child->genes[i] = partner->genes[i];
    }
  }
  return child;
};

void DNA::mutate(float mutationRate) {
  for (int i = 0; i < genes.size(); ++i) {
    if (ofRandom(1) < mutationRate) {
      const float angle = ofRandom(TWO_PI);
      genes[i] = ofVec2f(1, 0).rotateRad(angle);
      genes[i] *= ofRandom(maxForce);
    }
  }
};
