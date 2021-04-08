/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** solar
*/

#include "solar.hpp"

solar::solar()
{
    x = 10;
    y = 10;
    h = 30;
    w = 30;
    fox.push_back(new player(15, 15, "X"));
}

solar::~solar()
{
}

void solar::mapborder(IGraphicLib *GraphicLib)
{
    GraphicLib->printbox(h, w, x, y);
}

void solar::drawFood(IGraphicLib *GraphicLib, int x, int y)
{

}

int solar::run(IGraphicLib *GraphicLib)
{
    mapborder(GraphicLib);
    GraphicLib->printText(fox[0]->x, fox[0]->y, fox[0]->symbol);

    return 0;
}

void solar::getInput(int a)
{
}

extern "C"
{
    void *Launch()
    {
        return (new solar());
    }
}