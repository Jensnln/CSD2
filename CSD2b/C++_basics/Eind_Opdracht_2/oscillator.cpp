#include "oscillator.h"


Oscillator::Oscillator()
{
    std::cout << "Oscillator - Constructor \n";
}

Oscillator::Oscillator(float frequency) {
    this->frequency = frequency;

}

Oscillator::~Oscillator()
{
    std::cout << "Oscillator - Destructor \n";
}

void Oscillator::tick()
{
    phase += frequency / sampleRate;

    // Wrap phase
    if (phase > 1.0f) phase -= 1.0f;
    calculate();

}

float Oscillator::getSample()
{
    return sample;
}

void Oscillator::setSampleRate(float sampleRate)
{
    std::cout << "Inside setSampleRate()\n";
    std::cout << "New sampleRate:" << sampleRate << "\n";
    this-> sampleRate = sampleRate;
}

void Oscillator::setFrequency(float frequency) {
    std::cout << "Inside setFrequency()\n";
    this->frequency = frequency;
    std::cout << "New frequency: " << frequency << std::endl;
}

