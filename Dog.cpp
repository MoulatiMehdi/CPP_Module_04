
#include "Dog.hpp"
#include "Debug.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog")
{
    Debug::onConstructorDefault("Dog");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    Debug::onConstructorCopy("Dog");
}

Dog &Dog::operator=(const Dog &other)
{
    Debug::onOperatorCopyAssignment("Dog");
    if (&other == this)
        return *this;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    Debug::onDestructor("Dog");
}

const std::string &Dog::getType() const
{
    return _type;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof!!" << std::endl;
}
