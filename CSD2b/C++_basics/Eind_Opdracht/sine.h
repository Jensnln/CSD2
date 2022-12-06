#pragma once
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
    Sine(float frequency = 220, float samplerate = 44100);
    ~Sine();

    void calculate();


protected:

};