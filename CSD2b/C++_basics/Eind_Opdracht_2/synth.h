//
// Created by Jens on 14/12/2022.
//

#ifndef CSD_SYNTH_H
#define CSD_SYNTH_H
#include <iostream>

// Bass Class for the all synths.

class Synth{
public:
//    Const and Dest.
    Synth();
    ~Synth();

//    Function to set the samplerate.
    void setSampleRate(float sampleRate);

protected:
//    Variables for the entire class.
    float sampleRate;
};

#endif //CSD_SYNTH_H
