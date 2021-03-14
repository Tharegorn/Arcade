/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** ncurse
*/

#include "ncurse.hpp"

ncurse::ncurse()
{
    win = initscr();
    curs_set(FALSE);
    noecho();
}

ncurse::~ncurse()
{
    endwin();
}

int ncurse::getKey()
{
    return (getch());
}

void ncurse::printText(int x, int y, std::string text)
{
    mvprintw(x, y, text.c_str());
}

void ncurse::refresh()
{
    wrefresh(win);
}

extern "C" {
    void *Launch() {
        // ncurse *a = 
        return(new ncurse());
    }
}