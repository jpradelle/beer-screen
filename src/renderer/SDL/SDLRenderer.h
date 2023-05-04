#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#pragma once

#include "../IRenderer.h"
#include <SDL2/SDL.h>

class SDLRenderer : public IRenderer
{
public:
    SDLRenderer();
    ~SDLRenderer();

    void init();
    void draw(RendererPixel** pixels);

private:
    SDL_Window* m_win;

};

#endif