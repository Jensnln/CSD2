#include <iostream>
#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float samplerate) : Oscillator(frequency, samplerate)
{
    std::cout << "Sine - Constructor \n";
}

Sine::~Sine()
{
    std::cout << "~Sine - Destructor \n";
}


void Sine::calculate()
{
    sample = sin(M_PI * 2 * phase) * amplitude;
}