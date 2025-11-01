#include "Brain.hpp"

int main(int argc, char *argv[])
{
    Brain a;
    Brain b = a;

    a = b;

    return 0;
}
