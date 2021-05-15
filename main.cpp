/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** main
*/

#include <string>
#include <iostream>
#include <ncurses.h>

int main()
{
    int bite;
    initscr();
    bite = getch();
    endwin();
    std::cout << bite << std::endl;
}
