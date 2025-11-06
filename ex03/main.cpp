#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(int, char *[])
{
    MateriaSource a;
    MateriaSource b;
    AMateria     *d;

    a.learnMateria(new Cure());
    a.learnMateria(new Ice());
    d               = a.createMateria("ice");
    b               = a;
    MateriaSource c = b;

    delete d;
    std::cout << d << std::endl;

    return 0;
}
