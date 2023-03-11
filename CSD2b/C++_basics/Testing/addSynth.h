//
// Created by Jens on 13/12/2022.
//

#ifndef CSD_ADDSYNTH_H
#define CSD_ADDSYNTH_H
#include <iostream>
#include "synth.h"
#include "sine.h"
#define OSC_NUM 4

class addSynth : public Synth{
public:
    addSynth();
    addSynth(int osc_num);
    ~addSynth();
    int osc_num = OSC_NUM;

    //  Maak een lege pointer array aan met 1 plek.
    Oscillator* sineOsc[OSC_NUM];

    void addSynthPrint();
    void tick();

    void fillOscArray();

    void setSamplerate(float samplerate);

protected:
    float samplerate = 44100;
};

#endif //CSD_ADDSYNTH_H
