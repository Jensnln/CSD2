#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator(float frequency, float samplerate) : frequency(frequency), samplerate(samplerate)
{
    sample = 0;
    amplitude = 1.0;
    phase = 0;
    std::cout << "Oscillator - Constructor \n";
}

Oscillator::~Oscillator()
{
    std::cout << "Oscillator - Destructor \n";
}

void Oscillator::tick()
{
    phase += frequency / samplerate;

    // Wrap phase
    if (phase > 1.0f) phase -= 1.0f;
    calculate();

}

float Oscillator::getSample()
{
    return sample;
}

void Oscillator::setSamplerate(float samplerate)
{
    this-> samplerate = samplerate;
}

