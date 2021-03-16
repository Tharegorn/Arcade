/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-romain.bouguet [WSL: Ubuntu-20.04]
** File description:
** sdl
*/

#include "sdl2.hpp"

sdl::sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "SDL initialization failed." << std::endl;
		exit(EXIT_FAILURE);
	}
	win = SDL_CreateWindow("Arcade - SDL",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("../../assets/ARCADE.ttf", 2000);
    SDL_Delay(3000);
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
    SDL_SetRenderDrawColor(rend, 100, 0, 0, 255);
	SDL_RenderClear(rend);
}

void sdl::printText(int x, int y, std::string text)
{

    SDL_Color White = {255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), White); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(rend, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x; 
    Message_rect.y = y;
    Message_rect.w = 100;
    Message_rect.h = 100;
    SDL_RenderCopy(rend, Message, NULL, &Message_rect);
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