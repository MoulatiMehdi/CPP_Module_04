#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
  private:
    const static int _capacity = 4;
    std::string      _name;
    AMateria        *_inventory[_capacity];

  public:
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();

    const std::string &getName() const;

    void use(int idx, ICharacter &target);
    void equip(AMateria *m);
    void unequip(int idx);
};

#endif
