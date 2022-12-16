//
// Created by Jens on 14/12/2022.
//

#include "superSaw.h"

//
// Created by Jens on 14/12/2022.
//

#include "superSaw.h"

superSaw::superSaw(int oscNum) : oscNum(oscNum){
//    this->oscNum = oscNum; // Why does this not work?
    std::cout << "Inside superSaw()\n";
}

superSaw::~superSaw() {
    std::cout << "Inside ~superSaw()\n";

}

void superSaw::tick() {
    for(int i=0; i<oscNum; i++){
        oscBank[i].tick();
    }
}

//  Function to get all the sample values from the oscillators in the oscBank.
float superSaw::getSample() {
    float superSawSample = 0;
    for(int i=0; i<oscNum; i++){
        superSawSample += oscBank[i].getSample();
    }

    return  superSawSample;
}

//  Function to set all the oscillator frequency values in the oscBank.
void superSaw::setOscFrequency(float fundamental, float detune) {
    for (int i = 0; i < oscNum; i++){
        oscBank[i].setFrequency(fundamental + i + detune);
    }
}