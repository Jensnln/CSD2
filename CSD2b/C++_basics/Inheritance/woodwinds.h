#include "instrument.h"

class Woodwinds : public Instrument
{
public:
    // Constr / Deconstr
    Woodwinds(std::string sound, float pitch);
    ~Woodwinds();

    // Methods
    void blowing(std::string blowingSound);
    void breathing(float breathTime);

};