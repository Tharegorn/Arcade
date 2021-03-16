/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "../include/Library.hpp"

typedef void *(*function)();

Core::Core(std::string path)
{
    int ite = 0;
    bool current = false;
    check_files();
    for (const auto& x : libraries) {
        Listlib.push_back(new Library(x.second));
    }
    for (const auto& x : libraries) {
        if (x.second == path) {
            curr = ite;
            current = true;
        }
        ite++;
    }
    maxlib = ite - 1;
    if (!current) {
        Listlib.push_back(new Library(path));
        curr = Listlib.size() - 1;
    }
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
            if (strcmp(diread->d_name, ".") && strcmp(diread->d_name, ".."))
                files.push_back(diread->d_name);
        }
        closedir (dir);
    } else {
        perror ("opendir");
    }
    for (auto i : files){
        t++;
        std::string str(i);
        if (str.find(".so") && str.find("arcade_"))
            files.erase(files.begin() + t - 1);
    }
    for (auto i : files) {
        std::string str(i);
        auto name = str;
        name.erase(0, 7);
        name.erase(name.length() - 3, 3);
        std::cout << name << ":" << str << std::endl;
        libraries[name] = "lib/" + str;
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

void Core::init()
{
    //int i = 2;
    while (1) {
        GraphicLib->clearwin();
       // GraphicLib->printbox(13, 10, 1, 1);
        GraphicLib->printText(0, 2, "Libraries");
        //for (const auto& x : libraries) {
        //    GraphicLib->printText(i,4, x.first);
        //    if (i - 2 == curr)
        //        GraphicLib->printText(i, 2, ">");
        //    i++;
        //}
      //  i = 2;
       // GraphicLib->printbox(25, 10, 1, 15);
       // GraphicLib->printText(0, 18, "Path");
       // for (const auto& x : libraries) {
       //     GraphicLib->printText(i,16, x.second);
       //     i++;
       // }
       // i = 2;
       // GraphicLib->printbox(12, 10, 1, 50);
       // GraphicLib->printText(0, 52, "Games");
       // GraphicLib->printbox(12, 10, 1, 65);
       // GraphicLib->printText(0, 67, "Path");
        GraphicLib->refresh();
        if (keys(GraphicLib->getKey()) == 84)
            break;
    }
}

int Core::keys(int key)
{
    if (key == NEXT_LIB) {
        delete(GraphicLib);
        if ((size_t)curr + 1 < Listlib.size())
            curr++;
        else
            curr = 0;
        this->LibLoader();
    }
    if (key == PREVIOUS_LIB) {
        delete(GraphicLib);
        if (curr - 1 >= 0)
            curr--;
        else
            curr = (int)Listlib.size();
        this->LibLoader();
    }
    if (key == EXIT) {
        delete(GraphicLib);
        return (84);
    }
    return 0;
}