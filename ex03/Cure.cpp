#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("ice") {}

Cure::Cure(const Cure &other) : AMateria(other._type) {}

Cure &Cure::operator=(const Cure &)
{
    return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &character)
{
    std::cout << "* heals " << character.getName() << "'s wounds *"
              << std::endl;
}
