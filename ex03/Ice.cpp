#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other._type) {}

Ice &Ice::operator=(const Ice &)
{
    return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &character)
{
    std::cout << "* shoots an ice bolt at " << character.getName() << " *"
              << std::endl;
}
