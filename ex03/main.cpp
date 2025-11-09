#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(int, char *[])
{
    MateriaSource a;
    MateriaSource b;
    AMateria * c = new Cure();
    a.learnMateria(c);
    a.learnMateria(new Ice());
    a.learnMateria(c);
    b               = a;

    std::cout << a.createMateria("cure") << std::endl;
    std::cout << a.createMateria("cure") << std::endl;
    std::cout << a.createMateria("cure") << std::endl;
    std::cout << a.createMateria("Unknown") << std::endl;

    return 0;
}
