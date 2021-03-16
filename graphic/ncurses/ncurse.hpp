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

class ncurse: IGraphicLib
{
    public:
        ncurse();
        ~ncurse();
        int getKey();
        void printText(int x, int y, std::string text);
        void refresh();
        void printbox(int x, int y, int h, int w);
    private:
        WINDOW *win;
};

#endif