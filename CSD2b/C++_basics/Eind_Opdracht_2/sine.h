#pragma once
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
    Sine();
    Sine(float frequency);
    ~Sine();

    void calculate();


protected:

};