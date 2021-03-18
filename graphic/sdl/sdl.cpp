/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** sdlè
*/

#include "sdl2.hpp"

sdl::sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exit(EXIT_FAILURE);
    if (TTF_Init() != 0)
        exit(EXIT_FAILURE);
    IMG_Init(IMG_INIT_PNG);
    win = SDL_CreateWindow("Arcade - SDL",
                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                           300, 300, SDL_WINDOW_SHOWN);
    SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);
    rend = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    if (rend == nullptr)
        exit(EXIT_FAILURE);
    font = TTF_OpenFont("assets/ARCADE.TTF", 200);
    back = IMG_LoadTexture(rend,
                           "assets/test.png");
}

sdl::~sdl()
{
    TTF_CloseFont(font);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int sdl::getKey()
{
    SDL_Event event;

    if (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
            return ('x');
        else if (event.type)
        {
            auto key = event.key.keysym.sym;
            if (key == SDLK_1)
                return ('1');
            if (key == SDLK_2)
                return ('2');
            if (key == SDLK_3)
                return ('3');
            if (key == SDLK_4)
                return ('4');
            if (key == SDLK_5)
                return ('5');
            if (key == SDLK_6)
                return ('6');
            if (key == SDLK_7)
                return ('7');
        }
    }
    return 0;
}

void sdl::clearwin()
{
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);
}

void sdl::printText(int x, int y, std::string text)
{
    SDL_Color White = {255, 255, 255, 255};

    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), White);

    SDL_Texture *Message = SDL_CreateTextureFromSurface(rend, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.y = y * 5;
    Message_rect.x = x * 5;
    Message_rect.w = text.length() * 10;
    Message_rect.h = 24;
    SDL_RenderCopy(rend, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void sdl::refresh()
{
    SDL_RenderPresent(rend);
}

void sdl::drawMenu(std::map<std::string, std::string> libraries, int curr)
{
    int a = 15;
    int ctt = 2;
    this->printText(150, 5, "ARCADE MENU -- SDL VESION");
    this->printText(8, 10, "LIBRARIES :");
    for (const auto &x : libraries)
    {
        if (ctt - 2 == curr)
            this->printText(8, a, "> " + x.first);
        else
            this->printText(8, a, x.first);
        a += 5;
        ctt++;
    }
    ctt = 2;
    this->printText(8, 130,"Keys:");
    this->printText(8, 135,"1 and 2 : switch to next or previous lib");
    this->printText(8, 140,"3 and 4 : switch to next or previous game");
    this->printText(8, 145,"5 : Restart Game");
    this->printText(8, 150,"6 : Return to menu");
    this->printText(8, 155,"7 : Exit Arcade");
    this->refresh();
}

void sdl::printbox(int x, int y, int h, int w)
{
}

extern "C"
{
    void *Launch()
    {
        return (new sdl());
    }
}