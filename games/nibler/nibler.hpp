/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** nibler
*/

#ifndef NIBLER_HPP_
#define NIBLER_HPP_

#include "../../include/IGames.hpp"
#include <time.h>

class nibler : IGames
{
public:
    nibler();
    ~nibler() override;
    void mapborder(IGraphicLib *GraphicLib);
    void drawFood(IGraphicLib *GraphicLib, int x, int y);
    int run(IGraphicLib *GraphicLib);
    void drawSnake(IGraphicLib *GraphicLib);
    int mooveSnake(IGraphicLib *GraphicLib);
    void getInput(int a);
    void init(IGraphicLib *GraphicLib);
    char libType() { return ('G');}




private:
    int x;
    int y;
    int h;
    int w;
    bool food = false;
    int dir = 4;
    std::vector<player *> snake;
    player *pfood;
    clock_t clk;
};

#endif /* !NIBLER_HPP_ */
