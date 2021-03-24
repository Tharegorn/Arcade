##
## EPITECH PROJECT, 2021
## B-OOP-400-LYN-4-1-arcade-romain.bouguet
## File description:
## Makefile
##

all:
	@make --no-print-directory -C main_core
	$(graphicals)
	$(games)



clean:
	@rm arcade
	@make clean  --no-print-directory -C main_core
	@make clean --no-print-directory -C graphic/ncurses/
	@make clean --no-print-directory -C graphic/sdl/
	@make clean --no-print-directory -C graphic/libcaca/
	@make clean --no-print-directory -C games/nibler/

fclean:
	@make fclean --no-print-directory -C main_core
	@make fclean --no-print-directory -C graphic/ncurses/
	@make fclean --no-print-directory -C graphic/sdl/
	@make fclean --no-print-directory -C graphic/libcaca/
	@make fclean --no-print-directory -C games/nibler/

re:
	@make re  --no-print-directory -C main_core
	@make re --no-print-directory -C graphic/ncurses/
	@make re --no-print-directory -C graphic/sdl/
	@make re --no-print-directory -C graphic/libcaca/
	@make re --no-print-directory -C games/nibler/

core:
	@make --no-print-directory -C main_core

games:
	@make --no-print-directory -C games/nibler/


graphicals:
	@make --no-print-directory -C graphic/ncurses/
	@make --no-print-directory -C graphic/sdl/
	@make --no-print-directory -C graphic/libcaca/