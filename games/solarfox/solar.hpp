/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** solar
*/

#ifndef SOLAR_HPP_
#define SOLAR_HPP_

#include "../../include/IGames.hpp"

class Mob
{
public:
    Mob(){}
    ~Mob();
    void set_pos(int x, int y, std::string c);
    std::string get_move() {return move;}
    void set_move(std::string str) {move = str;}
    std::vector<int> get_pos() {return pos;}
    std::string get_symbol() {return symbol;}

private:
    std::vector<int> pos;
    std::string symbol;
    std::string move;
};

class solar : IGames
{
public:
    solar();
    ~solar() override;
    void mapborder(IGraphicLib *GraphicLib);
    void drawFood(IGraphicLib *GraphicLib, int x, int y);
    int run(IGraphicLib *GraphicLib, std::string name);
    void getInput(int a);
    void set_input(int a);
    void moove_mob(IGraphicLib *GraphicLib);
    void Init(IGraphicLib *GraphicLib);
    char libType() { return ('G'); }

private:
    int x;
    int y;
    int h;
    int w;
    bool init = false;
    Player *fox;
    std::vector<Mob *> mob;
    int64_t mob_move = 500;
    int64_t shoot_time = 2000;
    std::chrono::high_resolution_clock::time_point latest_clock = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point shooter = std::chrono::high_resolution_clock::now();
};

#endif /* !SOLAR_HPP_ */
