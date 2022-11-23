#include "instrument.h"

class Stringed : public Instrument
{
public:
    // Const / Destr
    Stringed(std::string sound);
    ~Stringed();

    // // std::string sound;
    // // Methods
    // void pluck();
    // void strum();
};