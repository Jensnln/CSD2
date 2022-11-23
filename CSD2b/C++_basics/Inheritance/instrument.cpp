#include <iostream>
#include "instrument.h"


Instrument::Instrument(std::string sound, float pitch) :sound(sound), pitch(pitch)
{
    std::cout << "Inside the Instrument() constructor. \n";
}

Instrument::~Instrument()
{
    std::cout << "Inside the destructor.\n";
}

void Instrument::play()
{
    std::cout << "Inside play()\n";
    std::cout << "Playing Sound :" << sound <<  "\n";
    // std::cout << "Playing: \nsound: " << sound << " pitch: " << pitch 
    // << " amp: " << amp << " vel: " << vel << "\n";
    
}