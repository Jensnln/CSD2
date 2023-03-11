//
// Created by Jens on 13/12/2022.
//

#include "sine.h"
#include <iostream>
#include "math.h"

Sine::Sine(){
    std::cout << "Inside Sine()\n";
}

Sine::~Sine() {
    std::cout << "Inside ~Sine()\n";
}

void Sine::calculate() {
//    Set the sample to the new value based on the Sine class.
    std::cout << "Inside Sine::calculate() \n";
    sample = sin(M_PI * 2 * phase) * amplitude;
}