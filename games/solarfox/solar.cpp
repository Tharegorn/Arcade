/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** solar
*/

#include "solar.hpp"

solar::solar()
{
    x = 0;
    y = 0;
    h = 30;
    w = 30;
    fox = new Player(15, 15, "x");
    shoot = new Player(10, 10, "O");
    target = new Player(25, 16, "T");
    target_state = true;
}

solar::~solar()
{
}

void solar::move_player_shoot()
{
    moove_shot += 1;
    if (moove_shot > 2)
        shoot_state = false;
    else
    {
        if (shoot_dir == 1)
            shoot->y -= 1;
        if (shoot_dir == 2)
            shoot->y += 1;
        if (shoot_dir == 3)
            shoot->x -= 1;
        if (shoot_dir == 4)
            shoot->x += 1;
    }
}

void solar::display(IGraphicLib *GraphicLib, std::string name)
{
    mapborder(GraphicLib, name);
    for (auto &&i : mob)
    {
        if (i->get_shot_state() == true)
            GraphicLib->printText(i->get_shot_pos()[0], i->get_shot_pos()[1], i->get_shot_symbol().c_str());
        GraphicLib->printText(i->get_pos()[0], i->get_pos()[1], i->get_symbol().c_str());
    }
    if (target_state == true)
        GraphicLib->printText(target->x, target->y, target->symbol);
    if (shoot_state == true)
        GraphicLib->printText(shoot->x, shoot->y, shoot->symbol);
    GraphicLib->printText(fox->x, fox->y, fox->symbol);
}

void solar::move_shoot()
{
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
    }
}

int solar::get_highscore()
{
    std::ifstream file;
    std::string line;
    std::string stk;
    int ctt = 0;
    int tmp = 0;
    file.open("./assets/solar_score.txt");
    while (getline(file, line))
    {
        for (int i = 0; line[i]; i++)
        {
            if (line[i - 1] == ' ')
                ctt = 1;
            if (ctt == 1)
                stk.push_back(line[i]);
        }
        if (tmp < std::stoi(stk))
            tmp = std::stoi(stk);
        stk.clear();
        ctt = 0;
    }
    file.close();
    return (tmp);
}

void solar::highscore(std::string name)
{
    std::fstream my_file;

    if (name == "")
        name = "No_name";
    my_file.open("./assets/solar_score.txt", std::ios::app);
    my_file << name + " " + std::to_string(score) + "\n";
    my_file.close();
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
    if (fox->x >= w || fox->x <= x || fox->y >= h || fox->y <= y)
        return 1;
    for (auto &&i : mob)
    {
        if (i->get_shot_pos()[0] == fox->x && i->get_shot_pos()[1] == fox->y)
            return 1;
    }
    return 0;
}
void solar::mapborder(IGraphicLib *GraphicLib, std::string name)
{
    GraphicLib->printbox(h, w, x, y);
    GraphicLib->printText(35, 15, "Name : " + name);
    GraphicLib->printText(35, 20, "Score : " + std::to_string(score));
    if (score > get_highscore())
        GraphicLib->printText(35, 25, "HighScore : " + std::to_string(score));
    else
        GraphicLib->printText(35, 25, "HighScore : " + std::to_string(get_highscore()));
}

void solar::drawFood(IGraphicLib *GraphicLib, int x, int y)
{
}

void solar::check_move_shot()
{
    for (auto &&i : mob)
    {
        if (shoot->x == i->get_shot_pos()[0] && shoot->y == i->get_shot_pos()[1])
        {
            shoot_state = false;
            i->set_shot_state(false);
        }
    }
    if (shoot->x == target->x && shoot->y == target->y && target_state == true)
    {
        target_state = false;
        delete (target);
        score += 10;
    }
    if (target_state == false)
    {
        target = new Player(rand() % 19, rand() % 19, "T");
        target_state = true;
    }
}

void solar::init_shoot()
{
    if (shoot_state == false)
    {
        shoot_state = true;
        moove_shot = 0;
        shoot_dir = dir;
        if (shoot_dir == 1)
        {
            shoot->x = fox->x;
            shoot->y = fox->y - 2;
            shoot->symbol = "O";
        }
        if (shoot_dir == 2)
        {
            shoot->x = fox->x;
            shoot->y = fox->y + 2;
            shoot->symbol = "O";
        }
        if (shoot_dir == 3)
        {
            shoot->x = fox->x - 2;
            shoot->y = fox->y;
            shoot->symbol = "O";
        }
        if (shoot_dir == 4)
        {
            shoot->x = fox->x + 2;
            shoot->y = fox->y;
            shoot->symbol = "O";
        }
    }
}

void solar::set_input(int a)
{
    if (a == 5)
        init_shoot();
    else
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
    mob[0]->set_pos(20, 0, "M");
    mob[0]->set_move("LEFT");
    mob[0]->set_shot_pos(20, 0, "v");
    mob[0]->set_shot_move("DOWN");
    mob[1]->set_pos(30, 25, "M");
    mob[1]->set_move("DOWN");
    mob[1]->set_shot_pos(30, 25, "<");
    mob[1]->set_shot_move("LEFT");
    mob[2]->set_pos(13, 30, "M");
    mob[2]->set_move("RIGHT");
    mob[2]->set_shot_pos(13, 30, "^");
    mob[2]->set_shot_move("UP");
    mob[3]->set_pos(0, 22, "M");
    mob[3]->set_move("UP");
    mob[3]->set_shot_pos(0, 22, ">");
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
                mob[i]->set_pos(mob[i]->get_pos()[0] - 1, 0, "M");
            else
                mob[i]->set_pos(mob[i]->get_pos()[0] + 1, 0, "M");
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
                mob[i]->set_pos(0, mob[i]->get_pos()[1] + 1, "M");
            else
                mob[i]->set_pos(0, mob[i]->get_pos()[1] - 1, "M");
    }
    for (int i = 0; i != 4; i++)
    {
        if (i == 0)
        {
            if ((mob[i]->get_pos()[0] + 1) == 30)
                mob[i]->set_move("LEFT");
            if ((mob[i]->get_pos()[0] - 1) == 0)
                mob[i]->set_move("RIGHT");
        }
        if (i == 1)
        {
            if ((mob[i]->get_pos()[1] + 1) == 30)
                mob[i]->set_move("UP");
            if ((mob[i]->get_pos()[1] - 1) == 0)
                mob[i]->set_move("DOWN");
        }
        if (i == 2)
        {
            if ((mob[i]->get_pos()[0] + 1) == 30)
                mob[i]->set_move("LEFT");
            if ((mob[i]->get_pos()[0] - 1) == 0)
                mob[i]->set_move("RIGHT");
        }
        if (i == 3)
        {
            if ((mob[i]->get_pos()[1] + 1) == 30)
                mob[i]->set_move("UP");
            if ((mob[i]->get_pos()[1] - 1) == 0)
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
        if (mob[i]->get_shot_pos()[0] > w || mob[i]->get_shot_pos()[0] < x || mob[i]->get_shot_pos()[1] > h || mob[i]->get_shot_pos()[1] < y)
            mob[i]->set_shot_state(false);
    }
}
int solar::run(IGraphicLib *GraphicLib, std::string name)
{
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->latest_clock).count();
    auto delta_two = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->shooter).count();

    if (init == false)
        Init(GraphicLib);
    check_move_shot();
    if (mob_move <= delta) {
        moove_mob(GraphicLib);
        move_shoot();
        if (moove_fox(GraphicLib) == 1) {
            highscore(name);
            return -84;
        }
        this->latest_clock = now;
    }
    if (shoot_time <= delta_two) {
        move_player_shoot();
        this->shooter = now;
    }
    display(GraphicLib, name);
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
