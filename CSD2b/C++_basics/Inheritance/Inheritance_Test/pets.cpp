#include "pets.h"


Pets::Pets() : age(10), rating(9.1) 
{
    std::cout << "Pets() \n";
    std::cout << "Default age and rating: " << age << rating << "\n";
}

Pets::Pets(int age, float rating) : age(age), rating(rating)
{
    std::cout << "Pets() - Constructor \n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Rating: " << rating << "\n";
}

Pets::~Pets()
{
    std::cout << "~Pets() - Destructor\n";
}

void Pets::eat()
{
    std::cout << "Pets::eat() - Function \n";
    std::cout << "Eating \n";
}

void Pets::setName(std::string setname)
{
    std::cout << "Inside setName() \n";
    this-> name = setname;
    std::cout << "setName: " << setname << "\n";
}

std::string Pets::getName()
{
    std::cout << "Inside Pets::getName() \n";
    std::cout << "My name is: " << name << "\n";
    return name;
}