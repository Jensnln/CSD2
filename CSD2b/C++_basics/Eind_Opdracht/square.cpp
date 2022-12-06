#include <iostream>
#include "square.h"
#include "math.h"

Square::Square(float frequency, float samplerate) : Oscillator(frequency, samplerate)
{
    std::cout << "Square - Constructor \n";
}

Square::~Square()
{
    std::cout << "~Square - Destructor \n";
}


void Square::calculate()
{
    sample = amplitude;
    if(phase > 0.5) sample *=-1.0f;
}