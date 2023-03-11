//
// Created by Jens on 13/12/2022.
//

#ifndef CSD_SINE_H
#define CSD_SINE_H
#include "oscillator.h"

class Sine : public Oscillator
{
public:
    Sine();
    ~Sine();

    void calculate();
};


#endif //CSD_SINE_H
