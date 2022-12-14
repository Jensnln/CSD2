#include <iostream>
#include "saw.h"
#include "math.h"

//Sine::Sine(){
//    std::cout << "Inside Sine()\n";
//}

Saw::Saw()
{
    std::cout << "Saw - Constructor \n";
}

Saw::Saw(float frequency){
    Oscillator::frequency = frequency;
}

Saw::~Saw()
{
    std::cout << "~Saw - Destructor \n";
}


void Saw::calculate()
{
    sample = phase * 2 -1;
}