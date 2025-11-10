#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

int main()
{
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
        AMateria   *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    std::cout << std::string(50, '-') << std::endl;
    {
        MateriaSource a;

        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
                a.learnMateria(new Ice());
            else
                a.learnMateria(new Cure());
        }

        a.learnMateria(0);
        {
            MateriaSource b = a;
        }
        {
            MateriaSource b;
            b = a;
        }
        std::cout << a.createMateria("ice")->getType() << std::endl;
    }
    std::cout << std::string(50, '-') << std::endl;
    {
        Character jack("jack");
        Character bob("bob");
        AMateria * mm = new Cure();

        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 0)
                jack.equip(new Ice());
            else
                jack.equip(new Cure());
        }
        jack.unequip(1);
        jack.equip(new Ice());
        jack.equip(mm);
        jack.equip(0);

        for (int i = -1; i < 6; i++)
        {
            jack.use(i, bob);
        }

        std::cout << std::string(50, '-') << std::endl;

        jack.unequip(0);
        jack.use(0, bob);
        jack.equip(new Ice());
        jack.use(0, bob);
        jack.unequip(0);

        std::cout << std::string(50, '-') << std::endl;
        {
            Character jack_copy("jack_copy");
            Character jack1 = jack;

            jack_copy = jack;
            jack_copy.use(0, bob);
        }
        delete mm;
    }
    return 0;
}
