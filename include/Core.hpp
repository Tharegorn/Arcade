/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <dirent.h>
#include <string.h>
#include <map>
#include "Library.hpp"
#include "IGraphicLib.hpp"

class Core
{
    public:
        explicit Core(std::string);
        ~Core();
        void check_files();
        void LibLoader();
        void init();

    enum keys {
        PREVIOUS_LIB = 'p',
        NEXT_LIB = 'n',
        PEVIOUS_GAME = 'o',
        NEXT_GAME = 'l',
        RESTART = 'r',
        MENU = 'n',
        EXIT = 'x'
    };
    private:
        int curr;
        std::vector<char *> files;
        std::map<std::string, std::string> libraries;
        std::vector<Library *> Listlib;
        IGraphicLib *GraphicLib;
};
#endif /* !ARCADE_HPP_ */
