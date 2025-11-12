#include "WrongAnimal.hpp"
#include "Debug.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    Debug::onConstructorDefault("WrongAnimal");
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    Debug::onConstructorParameter("WrongAnimal");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    Debug::onConstructorCopy("WrongAnimal");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    Debug::onOperatorCopyAssignment("WrongAnimal");
    if (&other == this)
        return *this;
    type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    Debug::onDestructor("WrongAnimal");
}

void WrongAnimal::makeSound() const
{
    std::cout << "<WrongAnimal Sound>!!!" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
    return type;
}
