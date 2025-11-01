#include "Debug.hpp"

int main(int , char *[])
{

    Debug::onConstructorCopy("Name");
    Debug::onConstructorParameter("WrongCat");
    Debug::onConstructorDefault("Dog");
    Debug::onDestructor("WrongDog");
    Debug::onOperatorCopyAssignment("Animal");
    return 0;
}
