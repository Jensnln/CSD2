#include <iostream>
#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency, samplerate)
{
    std::cout << "Saw - Constructor \n";
}

Saw::~Saw()
{
    std::cout << "~Saw - Destructor \n";
}


void Saw::calculate()
{
    sample = phase * 2 -1;
}

void Saw::phaseCancel()
{
    phase *= -1;
}