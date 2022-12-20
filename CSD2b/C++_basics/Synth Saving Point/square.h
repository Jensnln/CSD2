//
// Created by Ciska Vriezenga on 06/12/2022.
//

#ifndef BLOK2B_SQUARE_H
#define BLOK2B_SQUARE_H

#include "oscillator.h"

class Square : public Oscillator{
public:
  Square();
  ~Square();
  void print(int instance);

protected:
  void calculate();
};

#endif //BLOK2B_SQUARE_H
