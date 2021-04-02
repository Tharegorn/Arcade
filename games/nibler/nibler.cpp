/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** nibler
*/

#include "nibler.hpp"

nibler::nibler()
{
    this->x = 10;
    this->y = 10;
    this->h = 30;
    this->w = 30;
}

nibler::~nibler() {}

void nibler::drawFood(IGraphicLib *GraphicLib, int x, int y)
{
    GraphicLib->printText(x, y, "F");
}

void nibler::drawSnake(IGraphicLib *GraphicLib)
{
    for (auto i : snake)
        GraphicLib->printText(i->x, i->y, i->symbol);
}

void nibler::getInput(int a)
{
    int nx = 0;
    int ny = 0;
    dir = a;
    if (a == 1) {
        nx = 0;
        ny = -1;
    } else if (a == 2) {
        nx = 0;
        ny = 1;
    } else if (a == 3) {
        nx = -1;
        ny = 0;
    } else if (a == 4) {
        nx = 1;
        ny = 0;
    }
    for (int i = snake.size() - 1; i != -1; i--) {
        if (i == 0) {
            snake[i]->x += nx;
            snake[i]->y += ny;
        } else {
            snake[i]->x = snake[i - 1]->x;
            snake[i]->y = snake[i - 1]->y;
        }
    }
}
int nibler::mooveSnake(IGraphicLib *GraphicLib)
{
    if (snake[0]->x == pfood->x && snake[0]->y == pfood->y) {
        int nx = snake[snake.size() - 1]->x;
        int ny = snake[snake.size() - 1]->y;
        delete (pfood);
        pfood = new player(rand() % 23 + 8, rand() % 23 + 8, "F");
        if (dir == 1)
            snake.push_back(new player(nx, ny + 1, "X"));
        if (dir == 2)
            snake.push_back(new player(nx, ny - 1, "X"));
        if (dir == 3)
            snake.push_back(new player(nx + 1, ny, "X"));
        if (dir == 4)
            snake.push_back(new player(nx - 1, ny, "X"));
    }
    for (int i = snake.size() - 1; i != 0; i--)
    {
        if (snake[0]->x == snake[i]->x && snake[0]->y == snake[i]->y)
            return -84;
    }
    if (snake[0]->x > this->x && snake[0]->x < this->w && snake[0]->y == this->y || snake[0]->y == this->h)
        return (-84);
    if (snake[0]->y > this->y && snake[0]->y < this->h && snake[0]->x == this->x || snake[0]->x == this->w)
        return (-84);
    return (0);
}

void nibler::init(IGraphicLib *GraphicLib)
{
    for (int i = 0; i != 4; i++) {
        if (i == 0)
        {
            player *p = new player((w / 2) - i, (h / 2), "0");
            snake.push_back(p);
        }
        else
        {
            player *p = new player((w / 2) - i, (h / 2), "X");
            snake.push_back(p);
        }
    }
}
int nibler::run(IGraphicLib *GraphicLib)
{
    GraphicLib->clearwin();
    if (food == false)
    {
        init(GraphicLib);
        pfood = new player(rand() % (this->w - 1) + (this->x + 1), rand() % (this->h - 1) + (this->y + 1), "F");
        food = true;
    }
    mapborder(GraphicLib);
    drawSnake(GraphicLib);
    if (mooveSnake(GraphicLib) == -84)
        return -84;
    drawFood(GraphicLib, pfood->x, pfood->y);
    // clk = clock() - clk;
    // if ((((double)clk) / CLOCKS_PER_SEC) == 0.1) {
    //     getInput(dir);
    //     clk = clock();
    // }
    GraphicLib->refresh();
    return (0);
}

void nibler::mapborder(IGraphicLib *GraphicLib)
{
    GraphicLib->printbox(h, w, x, y);
}
extern "C"
{
    void *Game()
    {
        return (new nibler());
    }
}