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

class player
{
    public:
        player(int x, int y, std::string symbol)
        {
            this->x = x;
            this->y = y;
            this->symbol = symbol;
        };
        int x;
        int y;
        std::string symbol;
};

class nibler : IGames
{
public:
    nibler();
    ~nibler() override;
    void mapborder(IGraphicLib *GraphicLib, int x, int y, int z, int v);
    void drawFood(IGraphicLib *GraphicLib, int x, int y);
    int run(IGraphicLib *GraphicLib);
    void drawSnake(IGraphicLib *GraphicLib);
    int mooveSnake(IGraphicLib *GraphicLib);
    void getInput(int a);



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
