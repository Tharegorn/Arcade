/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** IGraphicLib
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

#pragma once

class IGraphicLib {
    public:
        virtual ~IGraphicLib() = default;
        virtual void clearwin() = 0;
        virtual int getKey() = 0;
        virtual void printText(int x, int y, std::string text) = 0;
        virtual void refresh() = 0;
        virtual void printbox(int x, int y, int h, int w) = 0;
        virtual void drawMenu(std::map<std::string, std::string> libraries,std::map<std::string, std::string> games, int curr, int act) = 0;
        virtual void setName(char c) = 0;
        virtual void gameboard() = 0;
        virtual std::vector<int> get_board() = 0;

    protected:
    private:
};