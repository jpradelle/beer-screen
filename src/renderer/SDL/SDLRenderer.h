#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#pragma once

#include "../IRenderer.h"
#include "../../conf.h"
#include <SDL2/SDL.h>

#define PIXEL_SIZE 20
#define PIXEL_MARGIN 1

class SDLRenderer : public IRenderer
{
public:
    SDLRenderer();
    ~SDLRenderer();

    void init();
    int draw(RendererPixel pixels[MATRIX_WIDTH][MATRIX_HEIGHT]);
    void quit();

private:
    SDL_Window* m_win;
    SDL_Renderer* m_rend;
    SDL_Rect m_pixels[MATRIX_WIDTH][MATRIX_HEIGHT];

    int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius); // From https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
};

#endif