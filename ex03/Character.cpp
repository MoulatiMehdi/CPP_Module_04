#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

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
        _inventory[i] = 0;
    }
    for (int i = 0; i < _capacity; i++)
    {
        if (other._inventory[i])
        {
            _inventory[i] = _inventory[i]->clone();
            for (int j = i + 1; j < _capacity; j++)
            {
                if (other._inventory[i] == other._inventory[j])
                {
                    _inventory[j] = _inventory[i];
                }
            }
        }
    }
}

Character &Character::operator=(const Character &other)
{
    if (&other == this)
        return *this;
    _name = other._name;
    for (int i = 0; i < _capacity; i++)
    {
        _inventory[i] = 0;
    }
    for (int i = 0; i < _capacity; i++)
    {
        if (other._inventory[i])
        {
            _inventory[i] = other._inventory[i]->clone();
            for (int j = i + 1; j < _capacity; j++)
            {
                if (other._inventory[i] == other._inventory[j])
                {
                    _inventory[j] = _inventory[i];
                }
            }
        }
    }
    return *this;
}

Character::~Character() {}

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
        {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= _capacity || idx < 0 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
}
