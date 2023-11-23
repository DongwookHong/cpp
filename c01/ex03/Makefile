NAME	 =	violence
CXX		 =	c++ 
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
RM		 =	rm -rf

INCLUDE 	= HumanA.hpp \
			  HumanB.hpp \
			  Weapon.hpp

SRCS	 =	main.cpp \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp \
			

OBJS	 =	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean rex