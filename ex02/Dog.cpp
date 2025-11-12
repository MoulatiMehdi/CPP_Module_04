#include "Dog.hpp"
#include "Brain.hpp"
#include "Debug.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    Debug::onConstructorDefault("Dog");
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    Debug::onConstructorCopy("Dog");
}

Dog &Dog::operator=(const Dog &other)
{
    Debug::onOperatorCopyAssignment("Dog");
    if (&other == this)
        return *this;
    delete brain;
    Animal::operator=(other);
    brain = new Brain(*other.brain);
    return *this;
}

Dog::~Dog()
{
    Debug::onDestructor("Dog");
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof!!" << std::endl;
}
