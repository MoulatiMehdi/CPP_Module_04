#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

typedef void (**vfunc)(void);

int main()
{
    const Animal *meta = new Animal();
    const Animal *j    = new Dog();
    const Animal *i    = new Cat();

    vfunc f = *((vfunc *)i);

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "vfunction : " << std::endl;
    (**f)();
    return 0;
}
