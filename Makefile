CXX = c++
RM = rm 

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RMFLAGS = -rf 


NAME = run 
DEPS = Animal.hpp Debug.hpp
SRCS = Animal.cpp main.cpp Debug.cpp 
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
