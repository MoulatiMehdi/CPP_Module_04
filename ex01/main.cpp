#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
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
    title("\t Virtual Destructor");
    {
        int     size = 6;
        Animal *animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i * 2 > size)
                animals[i] = new Cat();
            else
                animals[i] = new Dog();
        }
        std::cout << std::endl;

        for (int i = 0; i < size; i++)
        {
            delete animals[i];
        }
    }
    title("\t Deep Copy");
    {
        Cat a;
        a.makeSound();
        std::cout << std::endl;
        {
            Cat b = a;
            b.makeSound();
        }
        std::cout << std::endl;
        Dog c;
        c.makeSound();
        std::cout << std::endl;
        {
            Dog d = c;
            d.makeSound();
        }

        std::cout << std::endl;
    }
    title("\t Const Objects");
    {
        const Cat a;
        Cat       b = a;

        b = a;
        std::cout << a.getType() << std::endl;
        a.makeSound();
    }
    std::cout << std::endl;
    {
        const Dog a;
        Dog       b = a;

        b = a;

        std::cout << a.getType() << std::endl;
        a.makeSound();
    }
    std::cout << std::endl;
    {
        const Animal a;
        Animal       b = a;

        b = a;

        std::cout << a.getType() << std::endl;
        a.makeSound();
    }
    std::cout << std::endl;
    return 0;
}
