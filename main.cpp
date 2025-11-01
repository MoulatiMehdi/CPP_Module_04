#include "Debug.hpp"

int main(int argc, char *argv[])
{

    Debug::onConstructorCopy("Name");
    Debug::onConstructorParameter("WrongCat");
    return 0;
}
