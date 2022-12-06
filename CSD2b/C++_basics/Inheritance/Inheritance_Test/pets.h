#pragma once
#include <iostream>

class Pets
{
    public:
        Pets();
        Pets(int age, float rating);
        ~Pets();
        float rating;
        void eat();

        // Set and Get
        void setName(std::string setname);
        std::string getName();

    protected:
        int age;
        void sleep();


    private:
        std::string name;

};