#include "Pool.hpp"
#include "AMateria.hpp"

Pool::Node *head = 0;

Pool::Pool() : _head(0) {}

Pool::Pool(const Pool &other) : _head(other._head) {}

Pool &Pool::operator=(const Pool &other)
{
    if (this == &other)
        return *this;
    _head = other._head;
    return *this;
}

Pool::~Pool()
{
    Pool::Node *p = _head;
    Pool::Node *next;
    while (p)
    {
        next = p->_next;
        delete p;
        p = next;
    }
    _head = NULL;
}

Pool::Node *Pool::find(const AMateria *ptr) const
{
    Pool::Node *p = _head;
    while (p)
    {
        if (p->_data == ptr)
            return p;
        p = p->_next;
    }
    return 0;
}

void Pool::add(const AMateria *ptr)
{
    if (ptr == 0 || find(ptr) == 0)
        return;
    Node *n  = new Node(ptr);
    n->_next = _head;
    _head    = n;
}

void Pool::remove(const AMateria *ptr)
{
    Pool::Node *curr = _head;
    Pool::Node *prev = NULL;

    if (ptr == NULL || _head == NULL)
        return;
    if (_head->_data == ptr)
    {
        if (curr)
            _head = curr->_next;
        else
            _head = NULL;
        return delete curr;
    }
    while (curr->_next)
    {
        prev = curr;
        curr = curr->_next;
        if (curr->_data == ptr)
        {
            prev->_next = curr->_next;
            return delete curr;
        }
    }
}

/*******************************************************************/

Pool::Node::Node(const AMateria *data) : _next(0), _data(data) {}

Pool::Node::Node(const Pool::Node &other)
    : _data(other._data),
      _next(other._next)
{
}

Pool::Node &Pool::Node::operator=(const Pool::Node &other)
{
    if (this == &other)
        return *this;
    _data = other._data;
    _next = other._next;
    return *this;
}

Pool::Node::~Node()
{
    if (_data)
        delete _data;
    _data = NULL;
    _next = NULL;
}
