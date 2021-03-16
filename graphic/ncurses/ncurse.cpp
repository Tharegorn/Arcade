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

void ncurse::clearwin()
{
    wclear(win);
}

void ncurse::printText(int x, int y, std::string text)
{
    mvprintw(x, y, text.c_str());
}

void ncurse::refresh()
{
    wrefresh(win);
}

void ncurse::printbox(int x, int y, int h, int w)
{
    WINDOW *t = subwin(win, y, x, h, w);
    box(t, ACS_VLINE, ACS_HLINE);
    touchwin(t);
    wrefresh(t);
    wrefresh(win);
}

extern "C" {
    void *Launch() {
        return(new ncurse());
    }
}