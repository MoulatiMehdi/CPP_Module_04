#ifndef CAT_HPP
#define CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
    WrongCat();
    WrongCat(const WrongCat &);
    WrongCat &operator=(const WrongCat &);
    ~WrongCat();

    void makeSound() const;
};

#endif
