#ifndef PADDLE_H
#define PADDLE_H

#pragma once

#include "../../controller/IController.h"
#include "../../renderer/RendererPixel.h"
#include "../../controller/IController.h"
#include "../../conf.h"

#define PADDLE_HEIGHT 5

class Paddle
{
public:
    Paddle(int x);
    ~Paddle();
    void move(IController* controller);
    void draw(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT]);
    int getX() const;
    int getY() const;
    int getHeight() const;

private:
    int m_x, m_y;

};

#endif