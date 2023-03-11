//
// Created by Jens on 13/12/2022.
//

#include "addSynth.h"

addSynth::addSynth() {
    std::cout << "Inside addSynth() \n";
}

addSynth::addSynth(int osc_num) {
    this-> osc_num = osc_num;
    std::cout << "Inside addSynth() \n";
}

addSynth::~addSynth() {
    std::cout << "Inside ~addSynth() \n";
}

void addSynth::addSynthPrint() {
    std::cout << "Inside addSynthPrint \n";
    std::cout << "Samplerate: " << samplerate << "\nMidi: " << midi << std::endl;
}


void addSynth::fillOscArray() {
    // Fill the array based on the number of places in the pointer array.
//    osc_num--;
    std::cout << "osc_num: " << osc_num << std::endl;
    for (int i = 0; i < osc_num;i++){
        sineOsc[i] = new Sine;
        std::cout << "fillOA() iteration: " << i << std::endl;
    }
}

void addSynth::tick() {
    std::cout << "Inside addSynthTick()\n" << "osc_num: " << osc_num << std::endl;
    for (int i = 0; i < osc_num; i++) {
        sineOsc[i]->tick();
    }
}

void addSynth::setSamplerate(float samplerate) {
    this->samplerate = samplerate;
}


