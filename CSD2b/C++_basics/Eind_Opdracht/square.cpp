#include <iostream>
#include "square.h"

Square::Square()
{
    std::cout << "Square - Constructor \n";
}

Square::Square(float frequency){
    Oscillator::frequency = frequency;
}

Square::~Square()
{
    std::cout << "~Square - Destructor \n";
}


void Square::setPwm(float pwmFrequency, float pwmAmp){
    pwmSine.setFrequency(pwmFrequency);
    this->pwmAmp = pwmAmp;
}

void Square::calculate()
{
//    Make a variable to store the current phase from the pwmSine.
    float pwmSample = pwmSine.getSample();
//    Make a variable to calculate the pwm. You want the pwm to oscillate between -0.5 and +0.5, so you subtract 0.5.
    float pwm = (pwmSample - 0.5) * pwmAmp;

//    Set the sample value as amplitude;
    sample = amplitude;
//    A normal square has the sample value flipped at 0.5, now you are going to modulate the that value.
//        ->  if (phase > 0.5) sample *=-1.0f;
//    Now you want the value to be shifting between 0 and 1, so -0.5 and +0.5 as pwm.
    if(phase > (pwm + 0.5)) sample *=-1.0f;

//    Tick the pwmSine to get generate the new sample value.
    pwmSine.tick();
}