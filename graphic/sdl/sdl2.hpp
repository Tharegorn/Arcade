/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** sdl
*/

#pragma once

#include "../../include/IGraphicLib.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>

class sdl: IGraphicLib
{
    public:
        sdl();
        ~sdl() override;
        void clearwin();
        int getKey();
        void printText(int x, int y, std::string text);
        void refresh();
        void printbox(int x, int y, int h, int w);
        void drawMenu(std::vector<std::string> libraries, std::vector<std::string> games, int curr, int act);
        void setName(char c);
        char libType() { return ('L');}

    private:
        SDL_Window *win;
        SDL_Renderer *rend;
        TTF_Font *font;
        SDL_Texture *back;
        std::string name;
};