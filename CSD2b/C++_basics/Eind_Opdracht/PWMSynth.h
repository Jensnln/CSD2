//
// Created by Jens on 14/12/2022.
//

#ifndef CSD_PWMSYNTH_H
#define CSD_PWMSYNTH_H
#include <iostream>
#include "synth.h"
#include "square.h"
#include "sine.h"

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

    void setPwm(float pwmFrequency, float pwmAmp);

    void pwmSynth.init(float samplerate, float frequency, float samplerate, 330, 4, 0.15);

//    Sine sine(440);
    void makeOsc();





protected:
    int oscNum;

//        Oscillator* oscBank = new Sine[oscNum];
    Square* oscBank = new Square[oscNum];

//    Square* oscBank[4];
//    Sine pwmSine = Sine(1);
};


#endif //CSD_PWMSYNTH_H
