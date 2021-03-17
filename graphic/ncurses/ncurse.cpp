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

void ncurse::drawMenu(std::map<std::string, std::string> libraries, int curr)
{
    int i = 2;

    this->clearwin();
    this->printbox(13, 10, 1, 1);
    this->printText(0, 2, "Libraries");
    for (const auto &x : libraries)
    {
        this->printText(i, 4, x.first);
        if (i - 2 == curr)
            this->printText(i, 2, ">");
        i++;
    }
    i = 2;
    this->printbox(25, 10, 1, 15);
    this->printText(0, 18, "Path");
    for (const auto &x : libraries)
    {
        this->printText(i, 16, x.second);
        i++;
    }
    i = 2;
    this->printbox(12, 10, 1, 50);
    this->printText(0, 52, "Games");
    this->printbox(12, 10, 1, 65);
    this->printText(0, 67, "Path");
    this->refresh();
}
extern "C"
{
    void *Launch()
    {
        return (new ncurse());
    }
}