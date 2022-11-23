// Only compile once
#pragma once
#include <iostream>

class Instrument
{
public:
    // Constr / Destr 
    Instrument(std::string sound, float pitch);
    ~Instrument();
    
    // Methods
    void play();

protected:
    // Protected Declerations
    std::string sound;
    float pitch;
    float amp;
    float vel;
};