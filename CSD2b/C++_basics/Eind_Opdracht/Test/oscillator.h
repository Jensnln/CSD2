#pragma once
#include <cmath>
#include <iostream>



class Oscillator
{
public:
    Oscillator(float frequency, float samplerate);
    ~Oscillator();

    // Methods

    // Set & Get
    void setSamplerate(float samplerate);

    void setFrequency(float frequency);
    float getFrequency();


protected:
    const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
    float frequency;
    float samplerate;
    float amplitude = 0;
    float phase = 0;
    float sample;
    // sample contains the current sample


};