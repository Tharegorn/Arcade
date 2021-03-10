##
## EPITECH PROJECT, 2021
## B-OOP-400-LYN-4-1-arcade-romain.bouguet
## File description:
## Makefile
##

all:
	@make --no-print-directory -C main_core


clean:
	@rm arcade
	@make clean  --no-print-directory -C main_core

fclean:
	@make fclean  --no-print-directory -C main_core

re:
	@make re  --no-print-directory -C main_core