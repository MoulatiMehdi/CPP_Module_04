#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstring>

Character::Character(const std::string &name) : _name(name), _inventory()
{
    for (int i = 0; i < _capacity; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character &other) : _name(other._name), _inventory()
{
    for (int i = 0; i < _capacity; i++)
    {
        if (other._inventory[i])
            _inventory[i] = _inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    if (&other == this)
        return *this;
    _name = other._name;
    for (int i = 0; i < _capacity; i++)
    {
        if (other._inventory[i])
            _inventory[i] = _inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < _capacity; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

const std::string &Character::getName() const
{
    return _name;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= _capacity || idx < 0 || _inventory[idx] == NULL)
        return;
    _inventory[idx]->use(target);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < _capacity; i++)
    {
        if (_inventory[i] == NULL)
            _inventory[i] = m;
    }
}

void Character::unequip(int idx)
{
    if (idx >= _capacity || idx < 0 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
}
