NAME	=	PhoneBook
CC		=	c++ 
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

HEADERS = Contact.hpp \
          PhoneBook.hpp

SRCS	=	PhoneBook.cpp \
			Contact.cpp \
			main.cpp

OBJS	=	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re