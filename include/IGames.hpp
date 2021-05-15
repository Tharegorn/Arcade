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
#include <iomanip>
#include <time.h>
#include <chrono>
#include <fstream>

class Player
{
    public:
        Player(int x, int y, std::string symbol)
        {
            this->x = x;
            this->y = y;
            this->symbol = symbol;
        };
        int x;
        int y;
        std::string symbol;
};

class IGames {
    public:
        virtual ~IGames() = default;
        virtual int run(IGraphicLib *GraphicLib, std::string name) = 0;
        virtual void set_input(int a) = 0;
        virtual char libType() = 0;

    protected:
    private:
};

#endif /* !IGAMES_HPP_ */
