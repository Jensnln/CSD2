#pragma once
#include "oscillator.h"

class Sine : public Oscillator
{
public:
    Sine(float frequency, float samplerate);
    ~Sine();

    void tick();

private:
    float amplitude;
    float phase;


};