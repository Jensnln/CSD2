#include "stringed.h"

// Constr /  Destr
Stringed::Stringed(std::string sound) : Instrument(sound)
{
    std::cout << "Inside Stringed constructor";
}

Stringed::~Stringed()
{
    std::cout << "Inside the Stringed destructor\n";
}


// // Methods
// void Stringed::pluck()
// {
//     std::cout << "Pluck" << "\n";
// }

// void Stringed::strum()
// {
//     std::cout << "strum" << "\n";
// }