
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default Constructor is called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy Constructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy Assignement Operator is called" << std::endl;
    if (&other == this)
        return *this;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
}

const std::string &Dog::getType() const
{
    return _type;
}

void Dog::makeSound() const
{
    std::cout << "Haow Haow Haow!!!" << std::endl;
}
