/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** Igames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "IGraphicLib.hpp"
#include <time.h>
#include <iomanip>

class IGames {
    public:
        virtual ~IGames() = default;
        virtual void mapborder(IGraphicLib *GraphicLib) = 0;
        virtual void drawFood(IGraphicLib *GraphicLib, int x, int y) = 0;
        virtual int run(IGraphicLib *GraphicLib) = 0;
        virtual void getInput(int a) = 0;

    protected:
    private:
};

#endif /* !IGAMES_HPP_ */
