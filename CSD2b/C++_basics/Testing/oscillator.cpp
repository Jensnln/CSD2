//
// Created by Jens on 13/12/2022.
//

#include "oscillator.h"
#include <iostream>

Oscillator::Oscillator() {
    std::cout << "Inside Oscillator()\n";
    frequency = 220;
    amplitude = 1;
    phase = 0;
    samplerate = 44100;



}

Oscillator::~Oscillator() {
    std::cout << "Inside ~Oscillator\n";
}

void Oscillator::tick() {
//    std::cout << "Inside Oscillator::tick()\n";
    phase += frequency / samplerate;
    if (phase > 1.0f) phase -= 1.0f;
    calculate();
}

float Oscillator::getSample(){
    return sample;
}

void Oscillator::setSamplerate(float samplerate) {
    this-> samplerate = samplerate;
}