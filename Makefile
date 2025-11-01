RM = rm 
CXX = c++

RMFLAGS = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -g3

DEPS = Animal.hpp Cat.hpp Debug.hpp Dog.hpp
SRCS = Animal.cpp Cat.cpp Debug.cpp Dog.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = run 

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
