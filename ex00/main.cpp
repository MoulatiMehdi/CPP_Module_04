#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

void title(const std::string &name)
{
    const std::string rule(50, '-');
    std::cout << rule << std::endl;
    std::cout << name << std::endl;
    std::cout << rule << std::endl;
}

int main()
{

    {
        title("\tPolymorphism By Pointer:");
        const Animal *meta = new Animal();
        const Animal *j    = new Dog();
        const Animal *i    = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();
    }
    std::cout << std::endl;
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i    = new WrongCat();

        std::cout << i->getType() << " " << std::endl;

        i->makeSound();
        meta->makeSound();
    }

    {
        title("\tPolymorphism By Reference:");
        const Animal &meta = Animal();
        const Animal &j    = Dog();
        const Animal &i    = Cat();

        std::cout << j.getType() << " " << std::endl;
        std::cout << i.getType() << " " << std::endl;

        i.makeSound();
        j.makeSound();
        meta.makeSound();
    }
    std::cout << std::endl;
    {
        const WrongAnimal &meta = WrongAnimal();
        const WrongAnimal &i    = WrongCat();

        std::cout << i.getType() << " " << std::endl;

        i.makeSound();
        meta.makeSound();
    }
    return 0;
}
