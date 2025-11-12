#include "Cat.hpp"
#include "Brain.hpp"
#include "Debug.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    Debug::onConstructorDefault("Cat");
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
    Debug::onConstructorCopy("Cat");
}

Cat &Cat::operator=(const Cat &other)
{
    Debug::onOperatorCopyAssignment("Cat");
    if (&other == this)
        return *this;
    delete brain;
    Animal::operator=(other);
    brain = new Brain(*other.brain);
    return *this;
}

Cat::~Cat()
{
    Debug::onDestructor("Cat");
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow Meow!!" << std::endl;
}
