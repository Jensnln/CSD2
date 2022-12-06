#include <iostream>
#include "cats.h"
#include "dogs.h"


int main()
{
    Cats cat2();
    Cats cat1(10, 9.8);
    cat1.eat();
    cat1.setName("Bonny");
    // cat1.getName();
    cat1.logName(cat1.getName());
    cat1.setAge(24);

    return 0;
}