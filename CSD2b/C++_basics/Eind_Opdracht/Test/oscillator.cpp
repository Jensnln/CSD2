#include "oscillator.h"

Oscillator::Oscillator(float frequency, float samplerate)
{
    this -> frequency = frequency;
    this -> samplerate = samplerate;
    this -> amplitude = amplitude;
    this -> phase = phase;
    std::cout << "Oscillator - Constructor \n";
    std::cout << "Frequency: " << frequency << "\n";
    // std::cout << "Samplerate: " << samplerate << "\n";
}

Oscillator::~Oscillator()
{
    std::cout << "~Oscillator - Destructor \n";
}