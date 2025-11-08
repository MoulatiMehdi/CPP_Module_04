#ifndef POOL_HPP
#define POOL_HPP

#include "AMateria.hpp"

class Pool
{
  public:
    class Node
    {
      public:
        const AMateria *_data;
        Node           *_next;

        Node();
        Node(const AMateria *data);
        Node(const Node &other);
        Node &operator=(const Node &other);
        ~Node();
    };

    void  add(const AMateria *ptr);
    void  remove(const AMateria *ptr);
    Node *find(const AMateria *ptr) const;

  private:
    Pool::Node *_head;

    Pool();
    Pool(const Pool &other);
    Pool &operator=(const Pool &other);
    ~Pool();
};

#endif
