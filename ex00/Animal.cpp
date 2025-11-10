#include "Animal.hpp"
#include "Debug.hpp"
#include <iostream>
#include <string>

Animal::Animal() : type("Animal")
{
    Debug::onConstructorDefault("Animal");
}

Animal::Animal(const std::string &type) : type(type)
{
    Debug::onConstructorParameter("Animal");
}

Animal::Animal(const Animal &other) : type(other.type)
{
    Debug::onConstructorCopy("Animal");
}

Animal &Animal::operator=(const Animal &other)
{
    Debug::onOperatorCopyAssignment("Animal");
    if (&other == this)
        return *this;
    type = other.type;
    return *this;
}

Animal::~Animal()
{
    Debug::onDestructor("Animal");
}

void Animal::makeSound() const
{
    std::cout << "<Animal Sound>!!!" << std::endl;
}

const std::string &Animal::getType() const
{
    return type;
}
