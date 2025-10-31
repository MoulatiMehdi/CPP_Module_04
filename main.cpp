#include "Animal.hpp"

int main(int, char *[])
{
    Animal a;
    Animal b("Cat");
    Animal c = a;

    c = b;

    c.makeSound();
    b.makeSound();
    a.makeSound();
    return 0;
}
