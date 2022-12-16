#include <iostream>
#include "sine.h"
#include "math.h"

//Sine::Sine(){
//    std::cout << "Inside Sine()\n";
//}

Sine::Sine()
{
    std::cout << "Sine - Constructor \n";
}

Sine::Sine(float frequency){
    Oscillator::frequency = frequency;
}

Sine::~Sine()
{
    std::cout << "~Sine - Destructor \n";
}


void Sine::calculate()
{
    sample = sin(M_PI * 2 * phase) * amplitude;
}