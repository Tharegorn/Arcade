/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** ncurse
*/

#ifndef ncurses
#define ncurses

#include <ncurses.h>
#include "../../include/IGraphicLib.hpp"
#include <iostream>
#include <string>
#include "../../include/Core.hpp"

class ncurse: IGraphicLib
{
    public:
        ncurse();
        ~ncurse() override;
        int getKey();
        void clearwin();
        void printText(int x, int y, std::string text);
        void refresh();
        void printbox(int x, int y, int h, int w);
        void drawMenu(std::vector<std::string> libraries, std::vector<std::string> games, int curr, int act);
        void setName(char c);
        char libType() { return ('L');}

    private:
        WINDOW *win;
        std::string name;
};

#endif