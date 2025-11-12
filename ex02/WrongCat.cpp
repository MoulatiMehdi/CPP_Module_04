#include "WrongCat.hpp"
#include "Debug.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    Debug::onConstructorDefault("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    Debug::onConstructorParameter("WrongCat");
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    Debug::onOperatorCopyAssignment("WrongCat");
    if (&other == this)
        return *this;
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    Debug::onDestructor("WrongCat");
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow Meow!!" << std::endl;
}
