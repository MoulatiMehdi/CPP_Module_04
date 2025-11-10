#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : _used()
{
    clear();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    clear();
    copyUsed(other._used);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (&other == this)
        return *this;
    clear();
    copyUsed(other._used);
    return *this;
}

MateriaSource::~MateriaSource() {}

void MateriaSource::clear()
{
    for (int i = 0; i < _capacity; i++)
    {
        _used[i] = NULL;
    }
}

void MateriaSource::copyUsed(AMateria *const used[4])
{
    for (int i = 0; i < _capacity; i++)
    {
        if (_used[i] == NULL && used[i])
        {
            _used[i] = used[i]->clone();
            for (int j = i + 1; j < _capacity; j++)
            {
                if (used[i] == used[j])
                {
                    _used[j] = _used[i];
                }
            }
        }
    }
}

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
