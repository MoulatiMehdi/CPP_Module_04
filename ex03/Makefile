CXX = c++
RM  = rm 

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -g 
RMFLAGS  = -rf 

ABST =  ICharacter.hpp 
DEPS = AMateria.hpp Inventory.hpp  $(ABST)
SRCS =  Inventory.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)

NAME = run 

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@  $^  

%.o : %.c $(DEPS) 
	$(CXX) $(CXXFLAGS) -c -o $@  $< 

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

.PHONY : all fclean clean re 
