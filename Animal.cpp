#include "Animal.hpp"
#include "Debug.hpp"
#include <iostream>
#include <string>

Animal::Animal() : _type("Animal")
{
    Debug::onConstructorDefault("Animal");
}

Animal::Animal(const std::string &type) : _type(type)
{
    Debug::onConstructorParameter("Animal");
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    Debug::onConstructorCopy("Animal");
}

Animal &Animal::operator=(const Animal &other)
{
    Debug::onOperatorCopyAssignment("Animal");
    if (&other == this)
        return *this;
    _type = other._type;
    return *this;
}

Animal::~Animal()
{
    Debug::onDestructor("Animal");
}

void Animal::makeSound() const 
{
    std::cout << "Animal " << _type << " make a sound" << std::endl;
}
