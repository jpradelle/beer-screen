#ifndef TESTGAME_H
#define TESTGAME_H

#pragma once

#include "../IGame.h"

class TestGame : public IGame
{
public:
    TestGame();
    ~TestGame();
    virtual void nextFrame(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT], IController* controller1, IController* controller2, int deltaTime);

private:
    int m_x, m_y;

};

#endif