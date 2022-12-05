#include "stringed.h"

// Constr /  Destr
Stringed::Stringed(std::string sound, float pitch) : Instrument(sound, pitch)
{
    std::cout << "Inside Stringed constructor. \n";
}

Stringed::~Stringed()
{
    std::cout << "Inside the Stringed destructor. \n";
}


// Methods
void Stringed::pluck(std::string pluckSound)
{
    std::cout << pluckSound << "\n";
}

void Stringed::strum(std::string strumSound)
{
    std::cout << "strum" << "\n";
    std::cout << strumSound << "\n";

}