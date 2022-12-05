#include <iostream>
#include "sine.h"
#include "writeToFile.h"


int main()
{
    Sine sine(220);
    std::cout << "Sine frequency: " << sine.getFrequency() << "\n";

    WriteToFile fileWriter("output.csv", true);
    for (int i = 0; i < SAMPLERATE; i++) 
    {
        fileWriter.write(std::to_string(sine.getSample())) + "\n";
        sine.tick();
    }

    return 0;
}