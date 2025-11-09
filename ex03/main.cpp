#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>
#include <string>

int main(int, char *[])
{
    int       n = 5;
    AMateria *b[n];

    std::cout << "size of AMateria is : " << sizeof(b[0]) << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            b[i] = new Ice();
        else
            b[i] = new Cure();
    }

    delete b[4];
    delete b[0];
    std::cout << std::string(50, '-') << std::endl;

    return 0;
}
