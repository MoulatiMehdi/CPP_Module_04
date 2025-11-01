#include <string>

class Debug
{
  private:
    Debug();
    Debug(const Debug &other);
    Debug &operator=(const Debug &other);
    ~Debug();
    static const std::string sep;
    static const int         width;

  public:
    static void onConstructorCopy(const std::string &name);
    static void onConstructorParameter(const std::string &name);
    static void onConstructorDefault(const std::string &name);
    static void onOperatorCopyAssignment(const std::string &name);
    static void onDestructor(const std::string &name);
};
