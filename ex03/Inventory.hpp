#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "AMateria.hpp"

class Inventory
{
  private:
    typedef int        Index;
    static const Index _capacity = 4;

    Index     _size;
    AMateria *_items[_capacity];

  public:
    static const Index npos = -1;

    Inventory();
    Inventory(const Inventory &other);
    Inventory &operator=(const Inventory &other);
    ~Inventory();

    Index find(AMateria *m) const;
    bool  isFull() const;
    bool  isEmpty() const;

    void init();
    void clear();
    void clone(const Inventory &other);
    void add(AMateria *m);
    void remove(Index idx);
};

#endif
