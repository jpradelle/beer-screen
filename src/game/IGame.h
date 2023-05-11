#ifndef IGAME_H
#define IGAME_H

#pragma once

#include "../renderer/RendererPixel.h"
#include "../controller/IController.h"
#include "../conf.h"

class IGame
{
public:
    IGame();
    ~IGame();
    virtual void nextFrame(RendererPixel[MATRIX_WIDTH][MATRIX_HEIGHT], IController* controller1, IController* controller2) = 0;

private:

};

#endif