#include "WrongCat.hpp"
#include <iostream>

int main(int, char *[])
{
    const WrongCat    *b = new WrongCat();
    const WrongAnimal *a = new WrongCat();

    std::cout << "a type is : " << a->getType() << std::endl;
    std::cout << "b type is : " << b->getType() << std::endl;
    a->makeSound();
    b->makeSound();

    return 0;
}
