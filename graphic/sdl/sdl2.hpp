/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** sdl
*/

#pragma once

#include "../../include/IGraphicLib.hpp"
#include <SDL2/SDL.h>

class sdl: IGraphicLib
{
    public:
        sdl();
        ~sdl();
        int getKey();
        void printText(int x, int y, std::string text);
        void refresh();
        void printbox(int x, int y, int h, int w);
    private:
        SDL_Window *win;
        SDL_Renderer *rend;
};