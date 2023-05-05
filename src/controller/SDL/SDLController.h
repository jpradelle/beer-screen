#ifndef SDLCONTROLLER_H
#define SDLCONTROLLER_H

#pragma once

#include "../IController.h"
#include <SDL2/SDL.h>

class SDLController : public IController
{
public:
    SDLController(SDL_Scancode mapUp, SDL_Scancode mapDown, SDL_Scancode mapLeft, SDL_Scancode mapRight, SDL_Scancode mapButton1, SDL_Scancode mapButton2);
    ~SDLController();
    void update();
    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();
    bool isButton1();
    bool isButton2();
    bool isQuit();

private:
    SDL_Scancode m_mapUp;
    SDL_Scancode m_mapDown;
    SDL_Scancode m_mapLeft;
    SDL_Scancode m_mapRight;
    SDL_Scancode m_mapButton1;
    SDL_Scancode m_mapButton2;

    bool m_up = false;
    bool m_down = false;
    bool m_left = false;
    bool m_right = false;
    bool m_button1 = false;
    bool m_button2 = false;
    bool m_quit = false;

};

#endif