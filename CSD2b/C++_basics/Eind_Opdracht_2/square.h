#pragma once
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
    Square();
    Square(float frequency);
    ~Square();

    void calculate();


protected:

};