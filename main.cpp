#include "Dog.hpp"
#include <iostream>

int main(int, char *[])
{
    Dog       a;
    const Dog b = a;

    a.makeSound();
    b.makeSound();
    std::cout << b.getType();
    std::cout << a.getType();

    return 0;
}
