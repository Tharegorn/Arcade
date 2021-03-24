/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** nibler
*/

#include "nibler.hpp"

nibler::nibler()
{
}

nibler::~nibler(){}

void nibler::mapborder(IGraphicLib *GraphicLib, int x, int y, int z, int v)
{
    GraphicLib->printbox(x, y, z, v);
}

extern "C" {
    void *Game() {
        return (new nibler());
    }
}