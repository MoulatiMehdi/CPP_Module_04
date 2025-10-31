#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() : _type("unknown")
{
    std::cout << "Animal Default Constructor is called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << "Animal Paramter Constructor is called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    std::cout << "Animal Copy Constructor is called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Copy Assignement Operator is called" << std::endl;
    if (&other == this)
        return *this;
    _type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor is called" << std::endl;
}

void Animal::makeSound()
{
    std::cout << "Animal " << _type << " make a sound" << std::endl;
}
