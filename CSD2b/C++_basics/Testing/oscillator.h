//
// Created by Jens on 13/12/2022.
//

#ifndef CSD_OSCILLATOR_H
#define CSD_OSCILLATOR_H

class Oscillator{
public:
    Oscillator();
    ~Oscillator();

    void tick();

//    Set & Get
    void setFrequency(float frequency);
    float getFrequency();

    float getSample();

    void setSamplerate(float samplerate);

protected:
    virtual void calculate() = 0;
    float sample;
    float phase;
    float amplitude;
    float frequency;
    float samplerate;
};


#endif //CSD_OSCILLATOR_H
