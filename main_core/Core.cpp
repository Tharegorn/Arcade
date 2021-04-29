/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "../include/Library.hpp"
#include "../include/IGames.hpp"

typedef void *(*function)();

Core::Core(std::string path)
{
    int ite = 0;
    bool current = false;
    check_files();
    for (const auto x : libraries)
        Listlib.push_back(new Library("lib/arcade_" + x + ".so"));
    for (const auto x : games)
        Listgames.push_back(new Library("lib/arcade_" + x + ".so"));
    for (const auto x : libraries) {
        if ("lib/arcace_" + x + ".so" == path) {
            curr = ite;
            current = true;
        }
        ite++;
    }

    maxlib = ite - 1;
    actualgame = 0;
    if (!current) {
        Listlib.push_back(new Library(path));
        curr = Listlib.size() - 1;
    }
    act = INIT;
    LibLoader();
}

Core::~Core()
{
}

void Core::check_files()
{
    DIR *dir; struct dirent *diread;
    int t = 0;

    if ((dir = opendir("./lib/")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (strcmp(diread->d_name, ".") && strcmp(diread->d_name, "..") && strcmp(diread->d_name, ".gitignore"))
                    files.push_back(diread->d_name);
        }
        closedir (dir);
    } else
        perror ("opendir");
    for (auto i : files){
        t++;
        std::string str(i);
        if (str.find(".so") && str.find("arcade_")) {
                files.erase(files.begin() + t - 1);
        }
    }
    for (auto i : files) {
        std::string str(i);
        auto name = str;
        name.erase(0, 7);
        name.erase(name.length() - 3, 3);
        if (name == "ncurses" || name == "sdl2" || name == "libcaca" || name == "sfml")
            libraries.push_back(name);
        else
            games.push_back(name);
    }
}

void Core::LibLoader()
{
    function lib;
    char *err;

    lib = (function) dlsym(Listlib[curr]->get_open(), "Launch");
    if ((err = dlerror()) != nullptr) {
        std::cerr << err << std::endl;
        exit(84);
    }
    GraphicLib = static_cast<IGraphicLib *>(lib());

}

void Core::GameLoader()
{
    function lib;
    char *err;

    lib = (function) dlsym(Listgames[actualgame]->get_open(), "Launch");
    if ((err = dlerror()) != nullptr) {
        std::cerr << err << std::endl;
        exit(84);
    }
    Game = static_cast<IGames *>(lib());

}

void Core::init()
{
    while (1) {
        if (act == INIT)
            GraphicLib->drawMenu(libraries, games, curr, actualgame, name);
        else {
            GraphicLib->clearwin();
            if (Game->run(GraphicLib, name) == -84) {
                delete(Game);
                act = INIT;
                GraphicLib->clearwin();
                GraphicLib->drawMenu(libraries, games, curr, actualgame, name);
            }
        }
       GraphicLib->refresh();
       if (keys(GraphicLib->getKey()) == 84)
          break;
    }
}

int Core::keys(int key)
{
    if (key == NEXT_LIB || key == 169) {
       delete(GraphicLib);
        if ((size_t)curr + 1 < Listlib.size())
            curr++;
        else
            curr = 0;
        this->LibLoader();
    }
    if (key == PREVIOUS_LIB || key == 38) {
       delete(GraphicLib);
        if (curr - 1 == -1)
            curr = maxlib;
        else
            curr--;
       this->LibLoader();
    }
    if (key == NEXT_GAME || key == 39) {
       delete(Game);
        if ((size_t)actualgame + 1 < Listgames.size())
            actualgame++;
        else
            actualgame = 0;
        this->GameLoader();
    }
    if (key == PREVIOUS_GAME || key == 36) {
       delete(Game);
        if (actualgame - 1 == -1)
            actualgame = Listgames.size() - 1;
        else
            actualgame--;
       this->GameLoader();
    }
    if (key == RESTART || key == 40) {
        act = GAME;
        this->GameLoader();
    }
    if (key == MENU || key == 45)
        act = INIT;
    //restart : 40
    if (key == EXIT || key == 168) {
       delete(GraphicLib);
        return (84);
    }
    if (act == INIT) {
        if (key >= 'a' && key <= 'z')
            set_name(key);
        if (key == 127 || key == BACKSPACE)
            set_name('0');
    } else {
        if (key == 'd')
            Game->getInput(4);
        if (key == 's')
            Game->getInput(2);
        if (key == 'q')
            Game->getInput(3);
        if (key == 'z')
            Game->getInput(1);
    }
    return 0;
}

void Core::set_name(char c)
{
    if (c == '0') {
        if (strlen(this->name.c_str()) > 0)
            this->name.pop_back();
    } else
        this->name.push_back(c);
}