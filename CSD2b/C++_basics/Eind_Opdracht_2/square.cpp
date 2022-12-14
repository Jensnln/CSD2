#include <iostream>
#include "square.h"

Square::Square()
{
    std::cout << "Square - Constructor \n";
}

Square::Square(float frequency){
    Oscillator::frequency = frequency;
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