#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstring>

Character::Character(const std::string &name) : _name(name), _slot()
{
    std::memset(_slot, INVALID, sizeof(_slot[0]) * CAPACITY);
}

Character::Character(const Character &other) : _name(other._name), _slot()
{
    std::memcpy(_slot, other._slot, sizeof(_slot[0]) * CAPACITY);
}

Character &Character::operator=(const Character &other)
{
    if (&other == this)
        return *this;
    _name = other._name;
    std::memcpy(_slot, other._slot, sizeof(_slot[0]) * CAPACITY);
    return *this;
}

Character::~Character() {}

const std::string &Character::getName() const
{
    return _name;
}

bool Character::isInRange(int idx) const
{
    return idx >= 0 && idx < CAPACITY;
}

void Character::use(int idx, ICharacter &target)
{
    if (!isInRange(idx))
        return;
}

void Character::equip(AMateria *m)
{
    if (m == 0)
        return;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (_slot[i] == INVALID)
            _slot[i] = i;
    }
}

void Character::unequip(int idx)
{
    if (!isInRange(idx))
        return;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (_slot[i] == INVALID)
            _slot[i] = i;
    }
}
