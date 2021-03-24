/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** nibler
*/

#ifndef NIBLER_HPP_
#define NIBLER_HPP_

#include "../../include/IGames.hpp"

class nibler: IGames
{
    public:
        nibler();
        ~nibler() override;
        void mapborder(IGraphicLib *GraphicLib,int x, int y, int z, int v);
};

#endif /* !NIBLER_HPP_ */
