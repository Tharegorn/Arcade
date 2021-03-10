/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "../include/Library.hpp"


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
    if (!current) {
        Listlib.push_back(new Library(path));
    }
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
        if (str.find(".so") && str.find("lib_arcade_"))
            files.erase(files.begin() + t - 1);
    }
    for (auto i : files) {
        std::string str(i);
        auto name = str;
        name.erase(0, 11);
        name.erase(name.length() - 3, 3);
        libraries[name] = "./lib/" + str;
    }

}