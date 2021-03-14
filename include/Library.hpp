/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** Library
*/

#ifndef LIBRARY_HPP_
#define LIBRARY_HPP_

#include "Core.hpp"
#include <dlfcn.h>

class Library {
    public:
        explicit Library(std::string);
        ~Library();
        void *get_open();

    protected:
    private:
        void *open;
};

#endif /* !LIBRARY_HPP_ */
