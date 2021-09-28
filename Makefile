##
## EPITECH PROJECT, 2020
## makefile exe
## File description:
## fct
##

SRC	=	main.c \
		init_params.c \
		word_manager.c \
		split.c \
		my_strlen.c \

CFLAGS	=	-W -Wextra -Wall -Werror -g3

IFLAGS	=	-I include/

NAME	=	mixword

all:
	gcc -o $(NAME) $(SRC) $(IFLAGS) $(CFLAGS)

clean:
	rm -f *~
	rm -f *.o

fclean:
	rm -f $(NAME)

re:	fclean all
