#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstring>

Character::Character(const std::string &name)
    : _name(name),
      _size(0),
      _inventory()
{
    std::memset(_inventory, 0, sizeof(_inventory[0]) * _capacity);
}

Character::Character(const Character &other)
    : _name(other._name),
      _size(other._size)
{
    std::memcpy(
        _inventory, other._inventory, sizeof(_inventory[0]) * _capacity
    );
}

Character &Character::operator=(const Character &other)
{
    if (&other == this)
        return *this;
    _name = other._name;
    std::memcpy(
        _inventory, other._inventory, sizeof(_inventory[0]) * _capacity
    );
    return *this;
}

Character::~Character() {}

bool Character::isIndexValid(int idx) const
{
    return idx >= 0 && idx < _size;
}

bool Character::isMateriaExist(int idx) const
{
    if (!isIndexValid(idx))
        return false;
    return _inventory[idx] != NULL;
}

bool Character::isFull() const
{
    return _size == _capacity;
}

bool Character::isEmpty() const
{
    return _size == 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (!isMateriaExist(idx))
        return;
    _inventory[idx]->use(target);
}

void Character::equip(AMateria *m)
{
    if (m == 0 || isFull())
        return;
    _inventory[_size] = m->clone();
    _size++;
}

void Character::unequip(int idx)
{
    if (isEmpty() || !isMateriaExist(idx))
        return;
    for (int i = idx; i < _size - 1; i++)
    {
        _inventory[i] = _inventory[i + 1];
    }
    _inventory[_size - 1] = 0;
    _size--;
}

const std::string &Character::getName() const
{
    return _name;
}
