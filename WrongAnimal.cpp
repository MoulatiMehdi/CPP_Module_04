#include "WrongAnimal.hpp"
#include "Debug.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    Debug::onConstructorDefault("WrongAnimal");
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
    Debug::onConstructorParameter("WrongAnimal");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
    Debug::onConstructorCopy("WrongAnimal");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    Debug::onOperatorCopyAssignment("WrongAnimal");
    if (&other == this)
        return *this;
    _type = other._type;
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
    return _type;
}
