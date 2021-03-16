##
## EPITECH PROJECT, 2021
## B-OOP-400-LYN-4-1-arcade-romain.bouguet
## File description:
## Makefile
##

all:
	@make --no-print-directory -C main_core
	@make --no-print-directory -C graphic/ncurses/
	@make --no-print-directory -C graphic/sdl/


clean:
	@rm arcade
	@make clean  --no-print-directory -C main_core
	@make clean --no-print-directory -C graphic/ncurses/
	@make clean --no-print-directory -C graphic/sdl/

fclean:
	@make fclean --no-print-directory -C main_core
	@make fclean --no-print-directory -C graphic/ncurses/
	@make fclean --no-print-directory -C graphic/sdl/

re:
	@make re  --no-print-directory -C main_core
	@make re --no-print-directory -C graphic/ncurses/
	@make re --no-print-directory -C graphic/sdl/

core:
	@make --no-print-directory -C main_core

games:

graphicals:
	@make --no-print-directory -C graphic/ncurses/
	@make --no-print-directory -C graphic/sdl/
