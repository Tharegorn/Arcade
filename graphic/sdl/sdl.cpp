/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** sdl
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
		1920, 1080, SDL_WINDOW_SHOWN);
	//SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);
    rend = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("assets/ARCADE.TTF", 50);
    back = IMG_LoadTexture(rend,
		"assets/test.png");
    SDL_RenderPresent(rend);

}

sdl::~sdl()
{
    TTF_CloseFont(font);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int sdl::getKey()
{
    return 0;
}

void sdl::clearwin()
{
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	SDL_RenderClear(rend);
}

void sdl::printText(int x, int y, std::string text)
{
    SDL_Color White = {100, 255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), White); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(rend, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.y = y * 15;
    Message_rect.x = x * 15;
    Message_rect.w = text.length() * 10;
    Message_rect.h = 24;
    SDL_RenderCopy(rend, Message, &Message_rect, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void sdl::refresh()
{
    SDL_RenderPresent(rend);
}

void sdl::printbox(int x, int y, int h, int w)
{
}

extern "C" {
    void *Launch() {
        return(new sdl());
    }
}