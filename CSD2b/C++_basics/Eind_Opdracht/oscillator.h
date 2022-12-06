#pragma once
#include <iostream>
#include "oscillator.h"

class Oscillator 
{
public:
    Oscillator(float frequency, float samplerate);
    ~Oscillator();



    // Set and Get
    float getSample();
    void tick();
    void setSamplerate(float samplerate);




protected:
    virtual void calculate() = 0;
    float frequency;
    float samplerate;
    float sample;
    float phase;
    float amplitude;

};