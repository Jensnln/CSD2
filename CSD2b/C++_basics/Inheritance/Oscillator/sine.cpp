#include "sine.h"
#include "math.h"

Sine::Sine(float frequency)
{
    std::cout << "Sine - constructor \n";
    this->frequency = frequency;
}

Sine::~Sine()
{
    std::cout << "Sine - destructor\n";
}

float Sine::getSample()
{
    return sample;
}

void Sine::tick()
{
    
}

// Setters and getters
void Sine::setFrequency(float frequency)
{
    this->frequency = frequency;
}

float Sine::getFrequency()
{
    return frequency;
}