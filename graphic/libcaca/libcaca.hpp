/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** libcaca
*/

#ifndef LIBCACA_HPP_
#define LIBCACA_HPP_

#include "../../include/IGraphicLib.hpp"
#include <iostream>
#include <string>
#include "../../include/Core.hpp"
#include <caca++.h>
#include <caca.h>

class libcaca: IGraphicLib {
    public:
        libcaca();
        ~libcaca();
        int getKey();
        void clearwin();
        void printText(int x, int y, std::string text);
        void refresh();
        void printbox(int x, int y, int h, int w);
        void drawMenu(std::vector<std::string> libraries, std::vector<std::string> games, int curr, int act, std::string name);
        char libType() { return ('L');}

    private:
        caca_canvas_t *canva;
		caca_display_t *win;
};
#endif /* !LIBCACA_HPP_ */
