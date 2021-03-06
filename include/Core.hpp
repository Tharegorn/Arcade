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
#include "IGames.hpp"

class Core
{
    public:
        explicit Core(std::string);
        ~Core();
        void check_files();
        void LibLoader();
        void GameLoader();
        void init();
        void set_name(char c);
        std::string get_name() {return name;}
        int keys(int key);

    enum keys {
        PREVIOUS_LIB = '1',
        NEXT_LIB = '2',
        PREVIOUS_GAME = '3',
        NEXT_GAME = '4',
        RESTART = '5',
        MENU = '6',
        EXIT = '7',
        BACKSPACE = '8',
    };
    enum state {
        INIT = 0,
        GAME = 1
    };
    private:
        int curr;
        int maxlib;
        int actualgame;
        bool gamestate = false;
        std::vector<char *> files;
        std::vector<std::string> libraries;
        std::vector<std::string> games;
        std::vector<Library *> Listlib;
        std::vector<Library *> Listgames;
        IGraphicLib *GraphicLib;
        IGames *Game;
        state act;
        std::string name;
};
#endif /* !ARCADE_HPP_ */
