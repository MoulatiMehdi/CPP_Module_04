#include "Animal.hpp"

int main(int, char *[])
{
    Animal a;
    Animal b("Cat");
    Animal c = a;

    c = b;

    const Animal *const arr[] = {&a, &b, &c};
    int                 size  = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        arr[i]->getType();
        arr[i]->makeSound();
    }
    return 0;
}
