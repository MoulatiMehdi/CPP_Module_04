#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
  public:
    WrongAnimal();
    WrongAnimal(const std::string &type);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &);
    ~WrongAnimal();

    void               makeSound() const;
    const std::string &getType() const;

  protected:
    std::string _type;
};

#endif
