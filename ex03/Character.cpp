#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character(const std::string &name) : _name(name), _inventory()
{
    clear();
}

Character::Character(const Character &other) : _name(other._name), _inventory()
{
    copyInventory(other._inventory);
}

Character &Character::operator=(const Character &other)
{
    if (&other == this)
        return *this;
    _name = other._name;
    copyInventory(other._inventory);
    return *this;
}

Character::~Character() {}

void Character::copyInventory(AMateria *const inventory[4])
{
    clear();
    for (int i = 0; i < _capacity; i++)
    {
        if (inventory[i])
        {
            _inventory[i] = inventory[i]->clone();
            for (int j = i + 1; j < _capacity; j++)
            {
                if (inventory[i] == inventory[j])
                {
                    _inventory[j] = _inventory[i];
                }
            }
        }
    }
}

void Character::clear()
{
    for (int i = 0; i < _capacity; i++)
    {
        _inventory[i] = 0;
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
