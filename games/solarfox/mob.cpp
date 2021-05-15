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

void Mob::set_shot_pos(int x, int y, std::string c)
{
    shot_pos.clear();
    shot_pos.push_back(x);
    shot_pos.push_back(y);
    shot_symbol = c;
}

