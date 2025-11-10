#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    const static int _capacity = 4;
    AMateria        *_used[_capacity];

    void copyUsed(AMateria *const used[4]);
    void clear();

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &other);

    void      learnMateria(AMateria *);
    AMateria *createMateria(const std::string &type);
};

#endif
