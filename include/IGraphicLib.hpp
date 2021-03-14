/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** IGraphicLib
*/

#include <iostream>
#include <string>

#pragma once

class IGraphicLib {
    public:
        IGraphicLib();
        ~IGraphicLib();
        virtual int getKey();
        virtual void printText(int x, int y, std::string text);
        virtual void refresh();


    protected:
    private:
};