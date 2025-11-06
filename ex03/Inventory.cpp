#include "Inventory.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <cstring>

Inventory::Inventory() : _size(0), _used(), _unused()
{
    init();
}

Inventory::Inventory(const Inventory &other) : _size(0), _used(), _unused()
{
    init();
    for (Index i = 0; i < _capacity; i++)
    {
        if (other._used[i])
            _used[i] = other._used[i]->clone();
    }
}

Inventory &Inventory::operator=(const Inventory &other)
{
    if (this == &other)
        return *this;
    for (Index i = 0; i < _capacity; i++)
    {
        if (_used[i])
            delete _used[i];
        if (_unused[i])
            delete _unused[i];
    }
    init();
    for (Index i = 0; i < _capacity; i++)
    {
        if (other._used[i])
            _used[i] = other._used[i]->clone();
    }
    _size = other._size;

    return *this;
}

Inventory::Index Inventory::find(AMateria *m) const
{
    for (Index i = 0; i < _capacity; i++)
    {
        if (_used[i] == m)
            return i;
    }
    return npos;
}

void Inventory::remove(Index idx)
{
    if (idx < 0 || idx >= _capacity || _used[idx] == NULL)
        return;
    AMateria *ptr = _used[idx];
    _used[idx]    = NULL;
    _size--;
    if (find(ptr) != npos)
        return;

    for (Index i = 0; i < _capacity; i++)
    {
        if (_unused[i] == ptr)
            return;
    }
    for (Index i = 0; i < _capacity; i++)
    {
        if (_unused[i] == NULL)
        {
            _unused[i] = ptr;
            break;
        }
    }
}

void Inventory::add(AMateria *m)
{
    if (m == NULL)
        return;
    Index idx = find(NULL);
    if (idx == npos)
        return;
    for (Index i = 0; i < _capacity; i++)
    {
        if (_unused[i])
        {
            if (m != _unused[i])
                delete _unused[i];
            _unused[i] = 0;
        }
    }
    _used[idx] = m;
    _size++;
}

Inventory::~Inventory()
{
    for (Index i = 0; i < _capacity; i++)
    {
        if (_used[i])
            delete _used[i];
        if (_unused[i])
            delete _unused[i];
    }
}

void Inventory::init()
{
    std::memset(_used, 0, sizeof(_used[0]) * _capacity);
    std::memset(_used, 0, sizeof(_unused[0]) * _capacity);
}
