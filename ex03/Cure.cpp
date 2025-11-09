#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

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

void *Cure::operator new(std::size_t sz)
{
    std::cout << "Cure new operator is called" << std::endl;
    void *p = ::operator new(sz);

    return p;
}

void Cure::operator delete(void *ptr)
{
    std::cout << "Cure delete operator is called" << std::endl;
    ::operator delete(ptr);
}

void *Cure::operator new[](std::size_t sz)
{
    std::cout << "Cure new operator is called" << std::endl;
    void *p = ::operator new[](sz);

    return p;
}

void Cure::operator delete[](void *ptr)
{
    std::cout << "Cure delete operator is called" << std::endl;
    ::operator delete[](ptr);
}
