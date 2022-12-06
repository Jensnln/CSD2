#include "sine.h"

Sine::Sine(float frequency, float samplerate) : Oscillator(frequency, samplerate, amplitude, phase)
{
    std::cout << "Sine - Constructor\n";
    std::cout << "Frequency: " << frequency << "\n";
    std::cout << "Samplerate: " << samplerate << "\n";
    std::cout << "Amplitude: " << amplitude << "\n";
    std::cout << "Phase: " << phase << "\n";

}

Sine::~Sine()
{
    std::cout << "Sine - Destructor\n";
}

void Sine::tick()
{
    phase += frequency / samplerate;
    if(phase > 1.0f){
        phase -= 1.0f;
    }

    sample = sin(pi * 2 * phase) * amplitude;

}