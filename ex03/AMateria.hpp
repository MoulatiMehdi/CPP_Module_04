#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include "ICharacter.hpp"
#include "Pool.hpp"
#include <string>

class AMateria
{
  private:
    static Pool pool;

  protected:
    const std::string _type;
    static void       track(void *);
    static void       untrack(void *);

  public:
    AMateria(const std::string &type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();


    const std::string &getType() const;
    virtual AMateria  *clone() const = 0;
    virtual void       use(ICharacter &target);
};

#endif
