// Only compile once
#pragma once
#include <iostream>

class Instrument
{
public:
    Instrument(std::string sound);
    ~Instrument();
    
    void play();

protected:
    std::string sound;
};