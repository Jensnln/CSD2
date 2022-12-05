#pragma once
#include <iostream>

#define SAMPLERATE 44100

class Sine
{
public:
    Sine(float frequency);
    ~Sine();

    // Return the current sample
    float getSample();

    // Go to the next sample
    void tick();

    // Setters and getters
    void setFrequency(float frequency);
    float getFrequency();


private:
    float frequency;
    float phase = 0;
    // Contains the current sample
    float sample = 0;

};