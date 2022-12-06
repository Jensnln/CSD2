#pragma once
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
    Saw(float frequency = 220, float samplerate = 44100);
    ~Saw();

    void calculate();
    void phaseCancel();


protected:

};