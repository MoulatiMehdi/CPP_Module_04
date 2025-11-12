RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DEPS = AMateria.hpp  Character.hpp  Cure.hpp  Ice.hpp  MateriaSource.hpp  Pool.hpp ICharacter.hpp IMateriaSource.hpp
SRCS = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  MateriaSource.cpp  Pool.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = run 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o : %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

.PHONY : re fclean clean all 
