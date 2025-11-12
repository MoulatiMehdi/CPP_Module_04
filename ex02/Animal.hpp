#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  public:
    virtual ~Animal();

    virtual void       makeSound() const = 0;
    const std::string &getType() const;

  protected:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    Animal     &operator=(const Animal &other);
    std::string type;
};

#endif
