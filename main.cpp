#include "WrongAnimal.hpp"

int main(int, char *[])
{
    WrongAnimal a;
    WrongAnimal b("Cat");
    WrongAnimal c = a;

    c = b;

    const WrongAnimal *const arr[] = {&a, &b, &c};
    int                 size  = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        arr[i]->getType();
        arr[i]->makeSound();
    }
    return 0;
}
