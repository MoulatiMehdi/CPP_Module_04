#include "Dog.hpp"
#include <iostream>

int main(int, char *[])
{
    Dog       a;
    Dog c = a;
    const Dog b = a;

    a = b;

    std::cout << "b type is : " << b.getType() << std::endl;
    std::cout << "a type is : "<< a.getType() << std::endl;
    a.makeSound();
    b.makeSound();

    return 0;
}
