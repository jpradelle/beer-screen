#ifndef IRENDERER_H
#define IRENDERER_H

#pragma once

#include "RendererPixel.h"
#include "../conf.h"

class IRenderer
{
public:
    IRenderer();
    ~IRenderer();
    virtual void init() = 0;
    virtual int draw(RendererPixel pixels[MATRIX_WIDTH][MATRIX_HEIGHT]) = 0;
    virtual void quit() = 0;

private:

};

#endif