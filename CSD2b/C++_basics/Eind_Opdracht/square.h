#pragma once
#include <iostream>
#include "oscillator.h"
#include "sine.h"

class Square : public Oscillator
{
public:
    Square();
    Square(float frequency);
    ~Square();

    void calculate();

//    Set and Get
    void setPwm(float pwmFrequency, float pwmAmp);


protected:
    Sine pwmSine = Sine(1);
    float pwmAmp = 0.3;
};