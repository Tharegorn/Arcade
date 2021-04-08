##
## EPITECH PROJECT, 2021
## B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC     =   solar.cpp

CFLAGS	+=	-fPIC -Wextra -Wall -Werror

CFLAGS	+=	-I ../../include/ -I ./

OBJ     =	$(SRC:.c=.o)

NAME	=   arcade_solarfox.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -shared -fPIC -lncurses
	mv $(NAME) ../../lib/

clean:
	rm -f ../../lib/$(NAME)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
