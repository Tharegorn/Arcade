/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** nibler
*/

#ifndef NIBLER_HPP_
#define NIBLER_HPP_

#include "../../include/IGames.hpp"


class nibler : IGames
{
public:
    nibler();
    ~nibler() override;
    void mapborder(IGraphicLib *GraphicLib);
    void drawFood(IGraphicLib *GraphicLib, int x, int y);
    int run(IGraphicLib *GraphicLib, std::string name);
    void drawSnake(IGraphicLib *GraphicLib);
    int mooveSnake(IGraphicLib *GraphicLib);
    void getInput(int a);
    void set_input(int a);
    void draw_game(IGraphicLib *GraphicLib, std::string name);
    void highscore(std::string name);
    int get_highscore();
    void init(IGraphicLib *GraphicLib);
    char libType() { return ('G');}




private:
    int x;
    int y;
    int h;
    int w;
    int score = 0;
    bool food = false;
    int dir = 4;
    int64_t res = 500;
    std::vector<Player *> snake;
    Player *pfood;
    std::chrono::high_resolution_clock::time_point latest_clock = std::chrono::high_resolution_clock::now();
};

#endif /* !NIBLER_HPP_ */
