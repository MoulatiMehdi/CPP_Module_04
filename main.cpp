
#include "Animal.hpp"

int main(int , char *[])
{
    Animal a;
    Animal b("Cat");
    Animal c = a;

    c = b;
    return 0;
}
