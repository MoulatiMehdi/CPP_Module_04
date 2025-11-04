#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int main(int , char *[])
{
    AMateria *a = new Cure();
    AMateria *b = new Ice();
    AMateria *c = a->clone();
    AMateria *d = b->clone();

    std::cout << a << "\n" << c << std::endl;
    std::cout << b << "\n" << d << std::endl;

    std::cout << a->getType() << std::endl;
    std::cout << b->getType() << std::endl;
    std::cout << c->getType() << std::endl;
    std::cout << d->getType() << std::endl;

    delete a;
    delete b;
    delete c; 
    delete d;
    return 0;
}
