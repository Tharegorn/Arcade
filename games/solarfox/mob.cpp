/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** mob
*/

#include "solar.hpp"

void Mob::set_pos(int x, int y, std::string c)
{
    pos.clear();
    pos.push_back(x);
    pos.push_back(y);
    symbol = c;
}
