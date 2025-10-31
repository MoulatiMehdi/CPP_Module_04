#include <string>

class Animal
{
  public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &);
    ~Animal();

  protected:
    std::string _type;

  private:
};
