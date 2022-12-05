#include "woodwinds.h"
#include <iostream>

Woodwinds::Woodwinds(std::string sound, float pitch) : Instrument(sound, pitch)
{
    std::cout << "Inside Woodwinds constructor. \n";
}

Woodwinds::~Woodwinds()
{
    std::cout << "Inside Woodwinds destructor. \n";
}

void Woodwinds::blowing(std::string blowingSound)
{
    std::cout << blowingSound << std::endl;
}

void Woodwinds::breathing(float breathTime)
{
    std::cout << "You have " << breathTime << " seconds to breath.\n";
}