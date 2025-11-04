#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
  private:
    const static int CAPACITY = 4;
    const static int INVALID  = -1;
    std::string      _name;
    int              _slot[CAPACITY];
    

    bool isInRange(int idx) const;

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
