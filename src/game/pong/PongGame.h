#ifndef PONGGAME_H
#define PONGGAME_H

#pragma once

#include "../IGame.h"
#include "Paddle.h"

class PongGame : public IGame
{
public:
    PongGame();
    ~PongGame();
    void nextFrame(RendererPixel[MATRIX_WIDTH][MATRIX_HEIGHT], IController* controller1, IController* controller2);

private:
    Paddle m_paddleLeft;
    Paddle m_paddleRight;

};

#endif