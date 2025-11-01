#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  public:
    Brain();
    Brain(const Brain &);
    Brain &operator=(const Brain &);
    ~Brain();

  private:
    const static int _size = 100;
    std::string      ideas[_size];
};

#endif
