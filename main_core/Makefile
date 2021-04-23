##
## EPITECH PROJECT, 2021
## B-OOP-400-LYN-4-1-arcade-romain.bouguet
## File description:
## Makefile
##

SRC     =   Core.cpp        \
            main.cpp

CFLAGS	=	-Wall -Wextra -Werror -I ../include/ -ldl -std=c++17 -g3

OBJ     =	$(SRC:.cpp=.o)

NAME	=   arcade

all:	$(NAME)

$(NAME):	$(OBJ)
	@g++ $(OBJ) -o ../$(NAME) -ldl -fvisibility=hidden

%.o:	%.cpp
	g++ -c $(CFLAGS) $< -o $@

clean:
	@rm -rf ../arcade
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
