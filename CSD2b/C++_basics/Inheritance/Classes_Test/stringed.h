#include "instrument.h"

class Stringed : public Instrument
{
public:
    // Const / Destr
    Stringed(std::string sound, float pitch);
    ~Stringed();

    // // Methods
    void pluck(std::string pluckSound);
    void strum(std::string strumSound);
};