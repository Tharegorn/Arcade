/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet
** File description:
** libcaca
*/

#include "libcaca.hpp"

libcaca::libcaca()
{
    canva = caca_create_canvas(1920, 1080);
	win = caca_create_display(canva);
	if (win == nullptr)
		exit(EXIT_FAILURE);
	caca_set_display_title(win, "ARCADE -- LIBCACA VERSION");
}

libcaca::~libcaca()
{
    caca_free_display(win);
	win = nullptr;
	canva = nullptr;
}

int libcaca::getKey()
{
    caca_event_t event;

	if (caca_get_event(win, CACA_EVENT_KEY_RELEASE, &event, 0) == 1){
        int key = caca_get_event_key_ch(&event);
        if (key == CACA_KEY_F1)
            return '1';
        if (key == CACA_KEY_F2)
            return '2';
        if (key == CACA_KEY_F3)
            return '3';
        if (key == CACA_KEY_F4)
            return '4';
        if (key == CACA_KEY_F5)
            return '5';
        if (key == CACA_KEY_F6)
            return '6';
        if (key == CACA_KEY_F7)
            return '7';
        if (key >= 'a' && key <= 'z')
            return (key);
        if (key == CACA_KEY_BACKSPACE)
            return '8';
        if (key == ' ')
            return key;
    }
    return 0;
}
void libcaca::clearwin()
{
    caca_set_color_argb(canva, 0, 80);
	caca_clear_canvas(canva);
}
void libcaca::printText(int x, int y, std::string text)
{
    caca_set_color_ansi(canva, CACA_WHITE, CACA_BLACK);
	caca_put_str(canva, x, y, text.c_str());
	caca_set_attr(canva, 0);
}
void libcaca::refresh()
{
    caca_refresh_display(win);
}
void libcaca::printbox(int h, int w, int x, int y)
{
    for (int i = x; i <= w; i++) {
        for (int j = y; j <= h; j++) {
            if (i == x || i == w)
                printText(i, j, " ");
            if (j == y || j == h)
                printText(i, j, " ");
        }
    }
}
void libcaca::drawMenu(std::vector<std::string> libraries, std::vector<std::string> games, int curr, int act, std::string name)
{
    this->clearwin();
    int a = 5;
    int ctt = 2;
    this->printText(100, 0, "ARCADE - LIBCACA VERSION");
    this->printText(100, 3, "Name: " + name);
    this->printText(8, 2, "LIBRARIES");
    for (const auto x : libraries) {
        if (ctt - 2 == curr)
            this->printText(8, a, "> " + x);
        else
            this->printText(8, a, x);
        a += 1;
        ctt++;
    }
    a = 5;
    ctt = 2;
    this->printText(30, 2, "GAMES");
    for (const auto x : games) {
        if (ctt - 2 == act)
            this->printText(30, a, "> " + x);
        else
            this->printText(30, a, x);
        a += 1;
        ctt++;
    }
    a = 5;
    ctt = 2;
    this->printText(8, 20,"Keys:");
    this->printText(8, 22,"F1 and F2 : switch to next or previous lib");
    this->printText(8, 23,"F3 and F4 : switch to next or previous game");
    this->printText(8, 24,"F5 : Restart Game");
    this->printText(8, 25,"F6 : Return to menu");
    this->printText(8, 26,"F7 : Exit Arcade");
}

extern "C"
{
    void *Launch()
    {
        return (new libcaca());
    }
}
