#ifndef BALL_H
#define BALL_H

#pragma once

#include "../../renderer/RendererPixel.h"
#include "../../conf.h"
#include "Paddle.h"
class PongGame;

class Ball
{
public:
    Ball();
    ~Ball();
    void move(Paddle *paddleLeft, Paddle* paddleRight, PongGame* game, int deltaTime);
    void draw(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT]);
    void start();

private:
    float m_x, m_y, m_speed, m_angle;
};

#endif