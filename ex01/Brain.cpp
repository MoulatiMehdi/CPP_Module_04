#include "Brain.hpp"
#include "Debug.hpp"

Brain::Brain() : ideas()
{
    Debug::onConstructorDefault("Brain");
}

Brain::Brain(const Brain &other)
{
    Debug::onConstructorCopy("Brain");
    for (int i = 0; i < _size; i++)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    Debug::onOperatorCopyAssignment("Brain");
    if (this == &other)
        return *this;
    for (int i = 0; i < _size; i++)
    {
        ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    Debug::onDestructor("Brain");
}
