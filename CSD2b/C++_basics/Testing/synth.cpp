//
// Created by Jens on 13/12/2022.
//

#include "synth.h"

Synth::Synth(){
    std::cout << "Inside Synth() \n";

}

Synth::~Synth() {
    std::cout << "Inside ~Synth() \n";
}

void Synth::synthPrint() {
    std::cout << "Inside synthPrint() \n";
    std::cout << "Samplerate: " << samplerate << std::endl;
    std::cout << "Midi: " << midi << std::endl;
}


