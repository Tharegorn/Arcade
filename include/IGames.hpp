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
#include "IGraphicLib.hpp"

class IGames {
    public:
        virtual ~IGames() = default;
        virtual void mapborder(IGraphicLib *GraphicLib,int x, int y, int z, int v) = 0;

    protected:
    private:
};

#endif /* !IGAMES_HPP_ */
