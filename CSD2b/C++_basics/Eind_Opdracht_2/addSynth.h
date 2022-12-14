//
// Created by Jens on 14/12/2022.
//

#ifndef CSD_ADDSYNTH_H
#define CSD_ADDSYNTH_H
#include <iostream>
#include "synth.h"
#include "saw.h"
#include "sine.h"

class addSynth : public Synth{
public:
//    addSynth();
    addSynth(int oscNum);
    ~addSynth();

//    Function to tick all oscillators
    void tick();
    float getSample();

    void setOscFrequency(float fundamental);

//    Sine sine(440);
    void makeOsc();



protected:
        int oscNum;
//        Oscillator* oscBank = new Sine[oscNum];
        Oscillator* oscBank = new Saw[oscNum];
};

#endif //CSD_ADDSYNTH_H
