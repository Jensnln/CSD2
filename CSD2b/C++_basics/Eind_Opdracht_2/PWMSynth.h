//
// Created by Jens on 14/12/2022.
//

#ifndef CSD_PWMSYNTH_H
#define CSD_PWMSYNTH_H
#include <iostream>
#include "synth.h"
#include "square.h"

//
// Created by Jens on 14/12/2022.
//


class PWMSynth : public Synth{
public:
//    addSynth();
    PWMSynth(int oscNum);
    ~PWMSynth();

//    Function to tick all oscillators
    void tick();
    float getSample();

    void setOscFrequency(float fundamental);

//    Sine sine(440);
    void makeOsc();



protected:
    int oscNum;
//        Oscillator* oscBank = new Sine[oscNum];
    Oscillator* oscBank = new Square[oscNum];
};


#endif //CSD_PWMSYNTH_H
