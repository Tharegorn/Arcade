##
## EPITECH PROJECT, 2021
## B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC     =   libcaca.cpp

CFLAGS	+=	-fPIC -Wextra -Wall -Werror

CFLAGS	+=	-I ../../include/ -I ./

OBJ     =	$(SRC:.c=.o)

NAME	=   arcade_libcaca.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -shared -fPIC -lcaca
	mv $(NAME) ../../lib/

clean:
	rm -f ../../lib/$(NAME)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
