#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Pool AMateria::pool;

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria &AMateria::operator=(const AMateria &)
{
    return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << _type << " : " << target.getName() << std::endl;
}
