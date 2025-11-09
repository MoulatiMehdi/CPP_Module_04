#include "Pool.hpp"

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
        ::operator delete(p->_data);
        delete p;
        p = next;
    }
    _head = 0;
}

Pool::Node *Pool::find(void *ptr) const
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

void Pool::add(void *ptr)
{
    if (find(ptr) != 0)
        return;
    Node *n  = new Node(ptr);
    n->_next = _head;
    _head    = n;
}

void Pool::remove(void *ptr)
{
    Pool::Node *curr = _head;
    Pool::Node *prev = 0;

    if (_head == 0)
        return;
    if (_head->_data == ptr)
    {
        if (curr)
            _head = curr->_next;
        else
            _head = 0;
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

Pool::Node::Node(void *data) : _data(data), _next(0) {}

Pool::Node::Node(const Pool::Node &other)
    : _data(other._data),
      _next(other._next)
{
}

Pool::Node &Pool::Node::operator=(const Pool::Node &)
{
    return *this;
}

Pool::Node::~Node() {}
