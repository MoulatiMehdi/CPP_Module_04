#include "Cat.hpp"
#include "Debug.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat")
{
    Debug::onConstructorDefault("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    Debug::onConstructorParameter("Cat");
}

Cat &Cat::operator=(const Cat &other)
{
    Debug::onOperatorCopyAssignment("Cat");
    if (&other == this)
        return *this;
    Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    Debug::onDestructor("Cat");
}

const std::string &Cat::getType() const
{
    return _type;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow Meow!!" << std::endl;
}
