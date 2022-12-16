//
// Created by Jens on 14/12/2022.
//

#include "synth.h"

Synth::Synth(){
    std::cout << "Inside Synth()\n";
}

Synth::~Synth(){
    std::cout << "Inside ~Synth()\n";
}

void Synth::setSampleRate(float sampleRate) {
    this->sampleRate = sampleRate;
}

