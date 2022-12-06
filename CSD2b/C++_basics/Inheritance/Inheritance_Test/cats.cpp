#include "cats.h"

Cats::Cats() : Pets::Pets(age, rating)
{
    
    std::cout << "Cats() - Constructor\n";
    std::cout << "Cats() - Constructor\n";
}

Cats::Cats(int age, float rating) : Pets(age, rating)
{
    std::cout << "Cats() - Constructor\n";
}

Cats::~Cats()
{
    std::cout << "~Cats() - Destructor\n";

}

void Cats::logName(std::string name)
{
    std::cout << "Inside Cats::logName \n";
    std::cout << "My name is: " << name << "\n";
}

void Cats::setAge(int setAge)
{
    this -> age = setAge;
    std::cout << "New age: " << age << "\n";
}