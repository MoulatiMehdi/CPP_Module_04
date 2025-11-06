#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    const static int _capacity = 4;
    AMateria        *_used[_capacity];

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    ~MateriaSource();

    void      learnMateria(AMateria *);
    AMateria *createMateria(const std::string &type);
};

#endif
