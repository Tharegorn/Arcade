/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** solar
*/

#ifndef SOLAR_HPP_
#define SOLAR_HPP_

#include "../../include/IGames.hpp"
#include <time.h>

class solar : IGames
{
public:
    solar();
    ~solar() override;
    void mapborder(IGraphicLib *GraphicLib);
    void drawFood(IGraphicLib *GraphicLib, int x, int y);
    int run(IGraphicLib *GraphicLib, std::string name);
    void getInput(int a);
    char libType() { return ('G');}




private:
    int x;
    int y;
    int h;
    int w;
    std::vector<player *> fox;

};

#endif /* !SOLAR_HPP_ */
