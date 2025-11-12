#include "Cat.hpp"
#include "Debug.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    Debug::onConstructorDefault("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    Debug::onConstructorCopy("Cat");
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

void Cat::makeSound() const
{
    std::cout << "Meow Meow Meow!!" << std::endl;
}
