#pragma once

#include "ofMain.h"

class Perceptron {
public:
  void setup(int totalInputs, float learningRate);
  int feedforward(vector<float> inputs);
  int activate(float sum);
  void train(vector<float> inputs, int desired);

  float learningConstant;
  vector<float> weights;
};
