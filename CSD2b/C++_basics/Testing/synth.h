//
// Created by Jens on 13/12/2022.
//

#ifndef CSD_SYNTH_H
#define CSD_SYNTH_H
#include <iostream>

class Synth{
public:
    Synth();
    ~Synth();
    void synthPrint();


protected:
    float samplerate = 44100;
    int midi = 4;

};

#endif //CSD_SYNTH_H
