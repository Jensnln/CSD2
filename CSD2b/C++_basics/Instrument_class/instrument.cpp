#include <iostream>
#include "instrument.h"


Instrument::Instrument(std::string sound)
    :sound(sound)
{
    std::cout << "Inside the Instrument() constructor. \n";
}

Instrument::~Instrument()
{
    std::cout << "Inside the destructor\n";
}

void Instrument::play()
{
    std::cout << "Inside play()\n";
    std::cout << "Playing: " << sound << "\n";
    
}