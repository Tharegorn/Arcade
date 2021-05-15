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


void nibler::set_input(int a)
{
    dir = a;
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
        score++;
        if (res - 50 < 250)
            res = 250;
        else
            res -= 50;
        int nx = snake[snake.size() - 1]->x;
        int ny = snake[snake.size() - 1]->y;
        delete (pfood);
        pfood = new Player(rand() % 19 + 11, rand() % 19 + 11, "F");
        if (dir == 1)
            snake.push_back(new Player(nx, ny + 1, "X"));
        if (dir == 2)
            snake.push_back(new Player(nx, ny - 1, "X"));
        if (dir == 3)
            snake.push_back(new Player(nx + 1, ny, "X"));
        if (dir == 4)
            snake.push_back(new Player(nx - 1, ny, "X"));
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
    for (int i = 0; i != 30; i++) {
        if (i == 0)
        {
            Player *p = new Player((w / 2) - i, (h / 2), "0");
            snake.push_back(p);
        }
        else
        {
            Player *p = new Player((w / 2) - i, (h / 2), "X");
            snake.push_back(p);
        }
    }
}

void nibler::draw_game(IGraphicLib *GraphicLib, std::string name)
{
    if (food == false) {
        init(GraphicLib);
        pfood = new Player(rand() % (this->w - 1) + (this->x + 1), rand() % (this->h - 1) + (this->y + 1), "F");
        food = true;
    }
    mapborder(GraphicLib);
    drawSnake(GraphicLib);
    GraphicLib->printText(40, 10, "Score : " + std::to_string(score));
    GraphicLib->printText(40, 15, "Name : " + name);
    drawFood(GraphicLib, pfood->x, pfood->y);
}

void nibler::highscore(std::string name)
{
    std::fstream my_file;

    if (name == "")
        name = "No_name";
    my_file.open("./assets/nibler_score.txt", std::ios::app);
    my_file << name + " " + std::to_string(score) + "\n";
    my_file.close();
}
int nibler::run(IGraphicLib *GraphicLib, std::string name)
{
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->latest_clock).count();
    draw_game(GraphicLib, name);
    if (mooveSnake(GraphicLib) == -84) {
        highscore(name);
        free(pfood);
        for (auto &&i: snake)
            free(i);
        return -84;
    }
    if (res <= delta) {
        this->latest_clock = now;
        getInput(dir);
    }

    return (0);
}

void nibler::mapborder(IGraphicLib *GraphicLib)
{
    GraphicLib->printbox(h, w, x, y);
}
extern "C"
{
    void *Launch()
    {
        return (new nibler());
    }
}
