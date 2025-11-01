CXX = c++
RM = rm 

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RMFLAGS = -rf 


NAME = run 
DEPS = WrongAnimal.hpp WrongCat.hpp Debug.hpp
SRCS = WrongAnimal.cpp main.cpp WrongCat.cpp Debug.cpp 
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o : %.c
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)
fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

.PHONY : re fclean clean all 
