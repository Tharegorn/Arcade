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
    void set_shot_pos(int x, int y, std::string c);
    std::string get_move() {return move;}
    std::string get_shot_move() {return shot_move;}
    void set_move(std::string str) {move = str;}
    void set_shot_move(std::string str) {shot_move = str;}
    std::vector<int> get_pos() {return pos;}
    std::vector<int> get_shot_pos() {return shot_pos;}
    std::string get_symbol() {return symbol;}
    std::string get_shot_symbol() {return shot_symbol;}
    bool get_shot_state() { return shot_state;}
    void set_shot_state(bool state) {shot_state = state;}
private:
    std::vector<int> shot_pos;
    std::string shot_move;
    std::string shot_symbol;
    bool shot_state = false;
    std::vector<int> pos;
    std::string symbol;
    std::string move;
};

class solar : IGames
{
public:
    solar();
    ~solar() override;
    void mapborder(IGraphicLib *GraphicLib, std::string name);
    void drawFood(IGraphicLib *GraphicLib, int x, int y);
    int run(IGraphicLib *GraphicLib, std::string name);
    void getInput(int a);
    void set_input(int a);
    void moove_mob(IGraphicLib *GraphicLib);
    void Init(IGraphicLib *GraphicLib);
    char libType() { return ('G'); }
    int moove_fox(IGraphicLib *GraphicLib);
    void init_shoot();
    int check_fox_moove(IGraphicLib *GraphicLib);
    void check_move_shot();

private:
    int x;
    int y;
    int h;
    int w;
    bool init = false;
    Player *fox;
    Player *shoot;
    bool shoot_state = false;
    int shoot_dir;
    int moove_shot = 0;
    Player *target;
    bool target_state;
    std::vector<Mob *> mob;
    int dir = 2;
    int score = 0;
    int64_t mob_move = 700;
    int64_t shoot_time = 400;
    std::chrono::high_resolution_clock::time_point latest_clock = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point shooter = std::chrono::high_resolution_clock::now();
};

#endif /* !SOLAR_HPP_ */
