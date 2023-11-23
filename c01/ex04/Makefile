NAME	=	sed
CXX		=	c++ 
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

HEADERS = copy.hpp 

SRCS	=	main.cpp \
			copy.cpp 

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