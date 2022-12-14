//
// Created by Jens on 14/12/2022.
//

#include "addSynth.h"

addSynth::addSynth(int oscNum) : oscNum(oscNum){
//    this->oscNum = oscNum; // Why does this not work?
    std::cout << "Inside addSynth()\n";
}

addSynth::~addSynth() {
    std::cout << "Inside ~addSynth()\n";

}

void addSynth::tick() {
    for(int i=0; i<oscNum; i++){
        oscBank[i].tick();
    }
}

//  Function to get all the sample values from the oscillators in the oscBank.
float addSynth::getSample() {
    float addSynthSample = 0;
    for(int i=0; i<oscNum; i++){
        addSynthSample += oscBank[i].getSample();
    }

    return  addSynthSample;
}

//  Function to set all the oscillator frequency values in the oscBank.
void addSynth::setOscFrequency(float fundamental) {
    for (int i = 0; i < oscNum; i++){
        oscBank[i].setFrequency((fundamental * i) + fundamental);
    }
}