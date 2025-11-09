
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    Cure(const Cure &other);
    ~Cure();

    Cure &operator=(const Cure &other);
    void *operator new(std::size_t sz);
    void  operator delete(void *ptr);
    void *operator new[](std::size_t sz);
    void  operator delete[](void *ptr);

    void      use(ICharacter &target);
    AMateria *clone() const;
};

#endif
