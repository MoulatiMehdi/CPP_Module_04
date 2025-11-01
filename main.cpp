#include "Dog.hpp"
#include <iostream>

int main(int, char *[])
{
    Dog       a;
    const Dog b = a;
    Dog c = a;

    a = b;

    std::cout << b.getType() << std::endl;
    std::cout << a.getType() << std::endl;
    a.makeSound();
    b.makeSound();

    return 0;
}
