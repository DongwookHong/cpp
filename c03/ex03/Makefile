NAME	 =	a.out
CXX		 =	c++ 
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
RM		 =	rm -rf

SRCS	 =	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp
			

OBJS	 =	${SRCS:.c=.o}

all	:
	make $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re