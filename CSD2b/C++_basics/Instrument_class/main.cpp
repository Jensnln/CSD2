#include <iostream>
#include "instrument.h"

int main() 
{
    std::cout << "Inside main\n";
    Instrument myInstrument("Ratatatata");
    Instrument myInstrument_2("OOOEHH");
    myInstrument_2.play();
    myInstrument.play();
    return 0;
}