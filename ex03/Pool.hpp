#ifndef POOL_HPP
#define POOL_HPP

class Pool
{
  public:
    class Node
    {
      public:
        void *_data;
        Node *_next;

        Node(void *data);
        Node(const Node &other);
        Node &operator=(const Node &other);
        ~Node();
    };

  public:
    Pool();
    ~Pool();
    void add(void *ptr);
    void remove(void *ptr);

  private:
    Pool::Node *_head;
    Pool(const Pool &other);
    Pool &operator=(const Pool &other);
    Node *find(void *ptr) const;
};

#endif
