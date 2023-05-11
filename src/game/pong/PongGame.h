#ifndef PONGGAME_H
#define PONGGAME_H

#pragma once

#include "../IGame.h"
#include "Paddle.h"
#include "Ball.h"

class PongGame : public IGame
{
public:
    PongGame();
    ~PongGame();
    void nextFrame(RendererPixel[MATRIX_WIDTH][MATRIX_HEIGHT], IController* controller1, IController* controller2, int deltaTime);
    void scoreLeft();
    void scoreRight();

private:
    Paddle m_paddleLeft;
    Paddle m_paddleRight;
    Ball m_ball;
    bool m_started, m_gameOver;
    short m_scoreLeft, m_scoreRight;

};

#endif