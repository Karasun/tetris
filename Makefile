##
## EPITECH PROJECT, 2018
## PSU_navy_2018
## File description:
## Makefile-navy
##

SRC	=	src/main.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall		\
		-Wextra		\
		-I./include	\

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
