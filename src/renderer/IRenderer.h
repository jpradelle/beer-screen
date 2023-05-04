#ifndef IRENDERER_H
#define IRENDERER_H

#pragma once

#include "RendererPixel.h"

class IRenderer
{
public:
    IRenderer();
    ~IRenderer();
    virtual void init() = 0;
    virtual void draw(RendererPixel** pixels) = 0;

private:

};

#endif