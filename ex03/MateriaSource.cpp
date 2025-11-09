#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : _used()
{
    for (int i = 0; i < _capacity; i++)
    {
        _used[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < _capacity; i++)
    {
        _used[i] = NULL;
    }
    for (int i = 0; i < _capacity; i++)
    {
        if (_used[i] == NULL && other._used[i])
        {
            _used[i] = other._used[i]->clone();
            for (int j = i + 1; j < _capacity; j++)
            {
                if (other._used[i] == other._used[j])
                {
                    _used[j] = _used[i];
                }
            }
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (&other == this)
        return *this;
    for (int i = 0; i < _capacity; i++)
    {
        _used[i] = NULL;
    }
    for (int i = 0; i < _capacity; i++)
    {
        if (_used[i] == NULL && other._used[i])
        {
            _used[i] = other._used[i]->clone();
            for (int j = i + 1; j < _capacity; j++)
            {
                if (other._used[i] == other._used[j])
                {
                    _used[j] = _used[i];
                }
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < _capacity; i++)
    {
        if (_used[i] == NULL)
        {
            _used[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < _capacity; i++)
    {
        if (_used[i] && _used[i]->getType() == type)
        {
            return _used[i]->clone();
        }
    }
    return NULL;
}
