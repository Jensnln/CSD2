//
// Created by Jens on 14/12/2022.
//

#ifndef CSD_SUPERSAW_H
#define CSD_SUPERSAW_H
#include <iostream>
#include "synth.h"
#include "saw.h"

class superSaw : public Synth{
public:
//    addSynth();
    superSaw(int oscNum);
    ~superSaw();

//    Function to tick all oscillators
    void tick();
    float getSample();

    void setOscFrequency(float fundamental, float detune);

//    Sine sine(440);
    void makeOsc();



protected:
    int oscNum;
//        Oscillator* oscBank = new Sine[oscNum];
    Oscillator* oscBank = new Saw[oscNum];
};

#endif //CSD_SUPERSAW_H
