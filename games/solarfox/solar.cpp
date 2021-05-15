/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** solar
*/

#include "solar.hpp"

solar::solar()
{
    x = 10;
    y = 10;
    h = 30;
    w = 30;
    fox = new Player(15, 15, "x");
}

solar::~solar()
{
}

int solar::moove_fox(IGraphicLib *GraphicLib)
{
    if (dir == 1)
        fox->y -= 1;
    if (dir == 2)
        fox->y += 1;
    if (dir == 3)
        fox->x -= 1;
    if (dir == 4)
        fox->x += 1;
    if (check_fox_moove(GraphicLib) == 1)
        return 1;
    return 0;
}

int solar::check_fox_moove(IGraphicLib *GrapicLib)
{
    if (fox->x >= 30 || fox->x <= 10 || fox->y >= 30 || fox->y <= 1)
        return 1;
    for (auto &&i : mob) {
        if (i->get_shot_pos()[0] == fox->x && i->get_shot_pos()[1] == fox->y)
            return 1;
    }
    return 0;
}
void solar::mapborder(IGraphicLib *GraphicLib)
{
    GraphicLib->printbox(h, w, x, y);
}

void solar::drawFood(IGraphicLib *GraphicLib, int x, int y)
{
}

void solar::set_input(int a)
{
    dir = a;
    if (dir == 1)
        fox->y -= 1;
    if (dir == 2)
        fox->y += 1;
    if (dir == 3)
        fox->x -= 1;
    if (dir == 4)
        fox->x += 1;
}

void solar::Init(IGraphicLib *GraphicLib)
{
    for (int i = 0; i != 4; i++)
        mob.push_back(new Mob());
    mob[0]->set_pos(20, 10, "M");
    mob[0]->set_move("LEFT");
    mob[0]->set_shot_pos(20, 10, "v");
    mob[0]->set_shot_move("DOWN");
    mob[1]->set_pos(30, 25, "M");
    mob[1]->set_move("DOWN");
    mob[1]->set_shot_pos(30, 25, "<");
    mob[1]->set_shot_move("LEFT");
    mob[2]->set_pos(13, 30, "M");
    mob[2]->set_move("RIGHT");
    mob[2]->set_shot_pos(13, 30, "^");
    mob[2]->set_shot_move("UP");
    mob[3]->set_pos(10, 22, "M");
    mob[3]->set_move("UP");
    mob[3]->set_shot_pos(10, 22, ">");
    mob[3]->set_shot_move("RIGHT");
    mob[0]->set_shot_state(true);
    mob[1]->set_shot_state(true);
    mob[2]->set_shot_state(true);
    mob[3]->set_shot_state(true);
    init = true;
}

void solar::moove_mob(IGraphicLib *GraphicLib)
{
    for (int i = 0; i != 4; i++)
    {
        if (i == 0)
            if (mob[i]->get_move() == "LEFT")
                mob[i]->set_pos(mob[i]->get_pos()[0] - 1, 10, "M");
            else
                mob[i]->set_pos(mob[i]->get_pos()[0] + 1, 10, "M");
        if (i == 1)
            if (mob[i]->get_move() == "DOWN")
                mob[i]->set_pos(30, mob[i]->get_pos()[1] + 1, "M");
            else
                mob[i]->set_pos(30, mob[i]->get_pos()[1] - 1, "M");
        if (i == 2)
            if (mob[i]->get_move() == "RIGHT")
                mob[i]->set_pos(mob[i]->get_pos()[0] + 1, 30, "M");
            else
                mob[i]->set_pos(mob[i]->get_pos()[0] - 1, 30, "M");
        if (i == 3)
            if (mob[i]->get_move() == "DOWN")
                mob[i]->set_pos(10, mob[i]->get_pos()[1] + 1, "M");
            else
                mob[i]->set_pos(10, mob[i]->get_pos()[1] - 1, "M");
    }
    for (int i = 0; i != 4; i++)
    {
        if (i == 0)
        {
            if ((mob[i]->get_pos()[0] + 1) == 30)
                mob[i]->set_move("LEFT");
            if ((mob[i]->get_pos()[0] - 1) == 10)
                mob[i]->set_move("RIGHT");
        }
        if (i == 1)
        {
            if ((mob[i]->get_pos()[1] + 1) == 30)
                mob[i]->set_move("UP");
            if ((mob[i]->get_pos()[1] - 1) == 10)
                mob[i]->set_move("DOWN");
        }
        if (i == 2)
        {
            if ((mob[i]->get_pos()[0] + 1) == 30)
                mob[i]->set_move("LEFT");
            if ((mob[i]->get_pos()[0] - 1) == 10)
                mob[i]->set_move("RIGHT");
        }
        if (i == 3)
        {
            if ((mob[i]->get_pos()[1] + 1) == 30)
                mob[i]->set_move("UP");
            if ((mob[i]->get_pos()[1] - 1) == 10)
                mob[i]->set_move("DOWN");
        }
    }
    for (int i = 0; i != 4; i++)
    {
        if (mob[i]->get_shot_move() == "DOWN")
        {
            mob[i]->set_shot_pos(mob[i]->get_shot_pos()[0], mob[i]->get_shot_pos()[1] + 1, "v");
        }
        if (mob[i]->get_shot_move() == "UP")
        {
            mob[i]->set_shot_pos(mob[i]->get_shot_pos()[0], mob[i]->get_shot_pos()[1] - 1, "^");
        }
        if (mob[i]->get_shot_move() == "LEFT")
        {
            mob[i]->set_shot_pos(mob[i]->get_shot_pos()[0] - 1, mob[i]->get_shot_pos()[1], "<");
        }
        if (mob[i]->get_shot_move() == "RIGHT")
        {
            mob[i]->set_shot_pos(mob[i]->get_shot_pos()[0] + 1, mob[i]->get_shot_pos()[1], ">");
        }
        if (mob[i]->get_shot_pos()[0] > 30 || mob[i]->get_shot_pos()[0] < 10 || mob[i]->get_shot_pos()[1] > 30 || mob[i]->get_shot_pos()[1] < 10)
            mob[i]->set_shot_state(false);
    }
}
int solar::run(IGraphicLib *GraphicLib, std::string name)
{
    int i = 0;

    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->latest_clock).count();
    auto delta_two = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->shooter).count();
    (void)name;
    if (init == false)
        Init(GraphicLib);
    if (mob_move <= delta)
    {
        moove_mob(GraphicLib);
        if (moove_fox(GraphicLib) == 1)
            return -84;
        for (int i = 0; i != 4; i++)
        {
            if (mob[i]->get_shot_state() == false)
            {
                if (i == 0)
                {
                    mob[i]->set_shot_pos(mob[i]->get_pos()[0], mob[i]->get_pos()[1], "v");
                    mob[i]->set_shot_move("DOWN");
                    mob[i]->set_shot_state(true);
                }
                if (i == 1)
                {
                    mob[i]->set_shot_pos(mob[i]->get_pos()[0], mob[i]->get_pos()[1], "v");
                    mob[i]->set_shot_move("LEFT");
                    mob[i]->set_shot_state(true);
                }
                if (i == 2)
                {
                    mob[i]->set_shot_pos(mob[i]->get_pos()[0], mob[i]->get_pos()[1], "v");
                    mob[i]->set_shot_move("UP");
                    mob[i]->set_shot_state(true);
                }
                if (i == 3)
                {
                    mob[i]->set_shot_pos(mob[i]->get_pos()[0], mob[i]->get_pos()[1], "v");
                    mob[i]->set_shot_move("RIGHT");
                    mob[i]->set_shot_state(true);
                }
            }
        this->latest_clock = now;
    }
    if (shoot_time <= delta_two)
    {

        }
        this->shooter = now;
    }
    mapborder(GraphicLib);
    for (auto &&i : mob)
    {
        if (i->get_shot_state() == true)
            GraphicLib->printText(i->get_shot_pos()[0], i->get_shot_pos()[1], i->get_shot_symbol().c_str());
        GraphicLib->printText(i->get_pos()[0], i->get_pos()[1], i->get_symbol().c_str());
    }
    GraphicLib->printText(fox->x, fox->y, fox->symbol);
    return 0;
}

void solar::getInput(int a)
{
    
}

extern "C"
{
    void *Launch()
    {
        return (new solar());
    }
}
