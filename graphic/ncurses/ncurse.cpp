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
    mvprintw(y, x, text.c_str());
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
    this->printText(2, 0, "Libraries");
    for (const auto &x : libraries)
    {
        this->printText(4, i, x.first);
        if (i - 2 == curr)
            this->printText(2, i, ">");
        i++;
    }
    i = 2;
    this->printbox(25, 10, 1, 15);
    this->printText(18, 0, "Path");
    for (const auto &x : libraries)
    {
        this->printText(16, i, x.second);
        i++;
    }
    i = 2;
    for (const auto &x : games)
    {
        this->printText(53, i, x.first);
                if (i - 2 == act)
            this->printText(51, i, ">");
        i++;
    }
    i = 2;
    for (const auto &x : games)
    {
        this->printText(66, i, x.second);
        i++;
    }
    i = 2;
    this->printText(100, 0, "Name: " + name);
    this->printbox(12, 10, 1, 50);
    this->printText(52, 0, "Games");
    this->printbox(23, 10, 1, 65);
    this->printText(67, 0, "Path");
    this->printText(0, 15,"Keys:");
    this->printText(0, 16,"1 and 2 : switch to next or previous lib");
    this->printText(0, 17,"3 and 4 : switch to next or previous game");
    this->printText(0, 18,"5 : Restart Game");
    this->printText(0, 19,"6 : Return to menu");
    this->printText(0, 20,"7 : Exit Arcade");
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