#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default Constructor is called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Copy Constructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy Assignement Operator is called" << std::endl;
    if (&other == this)
        return *this;
    Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
}

const std::string &Cat::getType() const
{
    return _type;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
