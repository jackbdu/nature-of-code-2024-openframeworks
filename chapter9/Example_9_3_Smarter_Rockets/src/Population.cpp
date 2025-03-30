#include "Population.h"

void Population::setup(float _mutationRate, int length, int lifeSpan) {
  mutationRate = _mutationRate;
  generations = 0;

  for (int i = 0; i < length; ++i) {
    shared_ptr<DNA> dna = make_shared<DNA>();
    dna->setup(lifeSpan);
    Rocket rocket;
    rocket.setup(320, 220, dna);
    population.push_back(rocket);
  }
};

void Population::live(vector<Obstacle> obstacles, Obstacle target) {
  for (int i = 0; i < population.size(); ++i) {
    population[i].checkTarget(target);
    population[i].run(obstacles);
  }
};

bool Population::targetReached() {
  for (int i = 0; i < population.size(); ++i) {
    if (population[i].hitTarget)
      return true;
  }
  return false;
}

void Population::checkFitness() {
  for (int i = 0; i < population.size(); ++i) {
    population[i].calculateFitness();
  }
};

void Population::selection() {
  float totalFitness = 0;
  for (int i = 0; i < population.size(); ++i) {
    totalFitness += population[i].fitness;
  }

  for (int i = 0; i < population.size(); ++i) {
    population[i].fitness /= totalFitness;
  }
};

void Population::reproduction() {
  vector<Rocket> nextPopulation;
  for (int i = 0; i < population.size(); ++i) {
    shared_ptr<DNA> parentA = weightedSelection();
    shared_ptr<DNA> parentB = weightedSelection();
    shared_ptr<DNA> child = parentA->crossover(parentB);
    child->mutate(mutationRate);

    Rocket rocket;
    rocket.setup(320, 220, child);
    nextPopulation.push_back(rocket);
  }

  population.clear();
  population = nextPopulation;
  ++generations;
};

void Population::show() {
  for (int i = 0; i < population.size(); ++i) {
    population[i].show();
  }
};

shared_ptr<DNA> Population::weightedSelection() {
  int index = 0;
  float start = ofRandom(1);

  while (start > 0) {
    start = start - population[index].fitness;
    ++index;
  }

  --index;

  return population[index].dna;
};
