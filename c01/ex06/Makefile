NAME	=	harl
CXX		=	c++ 
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

HEADERS = Harl.hpp 

SRCS	=	main.cpp \
			Harl.cpp 

OBJS	=	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re