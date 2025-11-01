#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat &);
    Cat &operator=(const Cat &);
    ~Cat();

    void               makeSound() const;
    const std::string &getType() const;
};

#endif
