#pragma once
#include <iostream>
#include "oscillator.h"

class Oscillator 
{
public:
//    Oscillator();
    Oscillator();
    Oscillator(float frequency);
    ~Oscillator();



    // Set and Get
    float getSample();
    void tick();
    void setSampleRate(float sampleRate);
    void setFrequency(float frequency);




protected:
    virtual void calculate() = 0;
    float frequency = 0;
    float sampleRate = 44100;
    float sample = 0;
    float phase = 0;
    float amplitude = 1;

};