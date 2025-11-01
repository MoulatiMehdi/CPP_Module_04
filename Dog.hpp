#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
  public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &);
    ~Dog();

    void               makeSound() const;
    const std::string &getType() const;

  private:
};
