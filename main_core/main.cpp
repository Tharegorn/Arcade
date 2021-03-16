/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** main
*/

#include "Core.hpp"
#include "Library.hpp"
#include <dlfcn.h>


Library::Library(std::string file)
{
    char *err;
    open = dlopen(file.c_str(), RTLD_LAZY);
    if ((err = dlerror()) != nullptr) {
        std::cerr << err << std::endl;
        exit(84);
    }
    if (!open)
        std::cout << "Failed to open : '" << file.c_str() << "'" << std::endl;
}

Library::~Library()
{
    dlclose(open);
}

void *Library::get_open()
{
    return open;
}


int main( int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "ERROR: Invalid number of arguments" << std::endl;
        std::cout << "USAGE : ./arcade ./lib/lib_arcade.so" << std::endl;
        return -1;
    }
    Core *test = new Core(av[1]);
    test->init();
    return (0);
}