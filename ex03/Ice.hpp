
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    Ice(const Ice &other);
    ~Ice();

    Ice  &operator=(const Ice &other);
    void *operator new(std::size_t sz);
    void  operator delete(void *ptr);

    void      use(ICharacter &target);
    AMateria *clone() const;
};

#endif
