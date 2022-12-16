//
// Created by Jens on 14/12/2022.
//

#include "PWMSynth.h"


PWMSynth::PWMSynth(int oscNum) : oscNum(oscNum){
//    this->oscNum = oscNum; // Why does this not work?
    std::cout << "Inside PWMSynth()\n";
}

PWMSynth::~PWMSynth() {
    std::cout << "Inside ~PWMSynth()\n";

}

void PWMSynth::tick() {
    for(int i=0; i<oscNum; i++){
        oscBank[i].tick();
    }
//    pwmSine.tick();
}

//  Function to get all the sample values from the oscillators in the oscBank.
float PWMSynth::getSample() {
    float PWMSynthSample = 0;
    for(int i=0; i<oscNum; i++){
        PWMSynthSample += oscBank[i].getSample();
    }

    return  PWMSynthSample;
}

//  Function to set all the oscillator frequency values in the oscBank.
void PWMSynth::setOscFrequency(float fundamental) {
    for (int i = 0; i < oscNum; i++){
        oscBank[i].setFrequency((fundamental * i) + fundamental);
    }
}

void PWMSynth::setPwm(float pwmFrequency, float pwmAmp) {
    for (int i = 0; i < oscNum; i++){
        oscBank[i].setPwm(pwmFrequency, pwmAmp);
    }

}