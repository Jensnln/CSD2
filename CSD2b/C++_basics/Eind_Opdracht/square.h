#pragma once
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
    Square(float frequency = 220, float samplerate = 44100);
    ~Square();

    void calculate();


protected:

};