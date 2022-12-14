#pragma once
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
    Saw();
    Saw(float frequency);
    ~Saw();

    void calculate();


protected:

};