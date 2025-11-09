#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Pool.hpp"
#include <iostream>
#include <string>

int main(int, char *[])
{
    int       n = 5;
    Pool      a;
    AMateria *b[n];

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            b[i] = new Ice();
        else
            b[i] = new Cure();
        a.add(*b[i]);
    }
    a.add(*b[0]);
    a.remove(*b[2]);
    std::cout << std::string(50, '-') << std::endl;

    return 0;
}
