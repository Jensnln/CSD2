#include <iostream>
#include "stringed.h"
#include "woodwinds.h"

int main() 
{
    // std::cout << "Inside main\n";
    // Instrument myInstrument("Ratatata", 220, 0.3, 90);
    // myInstrument.play();
    Stringed guitar("WOOOOOOOH", 220);
    guitar.play();
    guitar.strum("Trrrrrrr");
    guitar.pluck("Pling");
    Woodwinds flute("Ffffft", 440);
    flute.blowing("Aahh");
    flute.breathing(3);

    return 0;
}