NAME		=	zombie
CXX			=	c++ 
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

INCLUDE 	= Zombie.hpp 

SRCS		=	main.cpp \
				Zombie.cpp \
				zombieHorde.cpp

OBJS		=	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp $(INCLUDE)
	@$(CXX) $(CFLAGS) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re