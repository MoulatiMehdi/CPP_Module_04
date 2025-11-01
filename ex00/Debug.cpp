#include "Debug.hpp"
#include <iomanip>
#include <iostream>
#include <string>

const std::string Debug::sep   = " : ";
const int         Debug::width = 11;

Debug::Debug() {}

Debug::~Debug() {}

Debug::Debug(const Debug &) {}

Debug &Debug::operator=(const Debug &)
{
    return *this;
}

void Debug::onDestructor(const std::string &name)
{
    std::cout << std::setw(width) << std::left << name;
    std::cout << sep << "Destructor is called" << std::endl;
}

void Debug::onOperatorCopyAssignment(const std::string &name)
{
    std::cout << std::setw(width) << std::left << name;
    std::cout << sep << "Copy Assignement Operator is called" << std::endl;
}

void Debug::onConstructorCopy(const std::string &name)
{
    std::cout << std::setw(width) << std::left << name;
    std::cout << sep << "Copy Constructor is called" << std::endl;
}

void Debug::onConstructorParameter(const std::string &name)
{
    std::cout << std::setw(width) << std::left << name;
    std::cout << sep << "Paramter Constructor is called" << std::endl;
}

void Debug::onConstructorDefault(const std::string &name)
{
    std::cout << std::setw(width) << std::left << name;
    std::cout << sep << "Default Constructor is called" << std::endl;
}
