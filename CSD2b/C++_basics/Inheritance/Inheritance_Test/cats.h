#pragma once
#include "pets.h"

class Cats : public Pets
{
    public:
        Cats();
        Cats(int age, float rating);
        ~Cats();


        void logName(std::string name);
        void setAge(int setAge);

    protected:

    private:

};