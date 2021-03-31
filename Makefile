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
	@make --no-print-directory -C graphic/libcaca/
	@make --no-print-directory -C games/nibler/
	# @make --no-print-directory -C games/solarfox/


clean:
	@rm arcade
	@make clean  --no-print-directory -C main_core
	@make clean --no-print-directory -C graphic/ncurses/
	@make clean --no-print-directory -C graphic/sdl/
	@make clean --no-print-directory -C graphic/libcaca/
	@make clean --no-print-directory -C games/nibler/
	# @make clean --no-print-directory -C games/solarfox/

fclean:
	@make fclean --no-print-directory -C main_core
	@make fclean --no-print-directory -C graphic/ncurses/
	@make fclean --no-print-directory -C graphic/sdl/
	@make fclean --no-print-directory -C graphic/libcaca/
	@make fclean --no-print-directory -C games/nibler/
	# @make fclean --no-print-directory -C games/solarfox/

re:
	@make re  --no-print-directory -C main_core
	@make re --no-print-directory -C graphic/ncurses/
	@make re --no-print-directory -C graphic/sdl/
	@make re --no-print-directory -C graphic/libcaca/
	@make re --no-print-directory -C games/nibler/
	# @make re --no-print-directory -C games/solarfox/

core:
	@make --no-print-directory -C main_core

games:
	@make --no-print-directory -C games/nibler/
	# @make --no-print-directory -C games/solarfox/


graphicals:
	@make --no-print-directory -C graphic/ncurses/
	@make --no-print-directory -C graphic/sdl/
	@make --no-print-directory -C graphic/libcaca/
