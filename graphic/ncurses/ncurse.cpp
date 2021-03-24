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

void ncurse::drawMenu(std::map<std::string, std::string> libraries,std::map<std::string, std::string> games, int curr, int act)
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
    for (const auto &x : games)
    {
        this->printText(i, 53, x.first);
                if (i - 2 == act)
            this->printText(i, 51, ">");
        i++;
    }
    i = 2;
    for (const auto &x : games)
    {
        this->printText(i, 66, x.second);
        i++;
    }
    i = 2;
    this->printText(0, 100, "Name: " + name);
    this->printbox(12, 10, 1, 50);
    this->printText(0, 52, "Games");
    this->printbox(23, 10, 1, 65);
    this->printText(0, 67, "Path");
    this->printText(15, 0,"Keys:");
    this->printText(16, 0,"1 and 2 : switch to next or previous lib");
    this->printText(17, 0,"3 and 4 : switch to next or previous game");
    this->printText(18, 0,"5 : Restart Game");
    this->printText(19, 0,"6 : Return to menu");
    this->printText(20, 0,"7 : Exit Arcade");
}

void ncurse::setName(char c)
{
    if (c == '0') {
        if (strlen(this->name.c_str()) > 0)
            this->name.pop_back();
    } else
        this->name.push_back(c);
}

extern "C"
{
    void *Launch()
    {
        return (new ncurse());
    }
}