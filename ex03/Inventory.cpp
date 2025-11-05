#include "Inventory.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <cstring>

Inventory::Inventory() : _size(0), _items()
{
    std::memset(_items, 0, sizeof(_items[0]) * _capacity);
}

Inventory::Inventory(const Inventory &other) : _size(0), _items()
{
    std::memset(_items, 0, sizeof(_items[0]) * _capacity);
    clone(other);
}

Inventory &Inventory::operator=(const Inventory &other)
{
    if (this == &other)
        return *this;
    _size = other._size;
    clear();
    clone(other);

    return *this;
}

void Inventory::clone(const Inventory &other)
{
    Index idx;
    for (Index i = 0; i < _capacity; i++)
    {
        if (other._items[i])
        {
            idx = other.find(other._items[i]);
            if (idx != i)
                _items[i] = _items[idx];
            else
                _items[i] = other._items[i]->clone();
        }
    }
}

Inventory::Index Inventory::find(AMateria *m) const
{
    for (Inventory::Index i = 0; i < _capacity; i++)
    {
        if (_items[i] == m)
            return i;
    }
    return npos;
}

void Inventory::add(AMateria *m)
{
    if (m == NULL)
        return;
    Index idx = find(NULL);
    if (idx == npos)
        return;
    _items[idx] = m->clone();
}

void Inventory::remove(Index idx)
{

}

void Inventory::clear()
{
    Index idx;
    for (Index i = 0; i < _capacity; i++)
    {
        idx = find(_items[i]);
        if (_items[i] && idx == i)
        {
            delete _items[i];
        }
    }
    std::memset(_items, 0, sizeof(_items[0]) * _size);
    _size = 0;
}

Inventory::~Inventory()
{
    clear();
}
