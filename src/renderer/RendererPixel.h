#ifndef RENDERERPIXEL_H
#define RENDERERPIXEL_H

#pragma once

class RendererPixel
{
public:
    RendererPixel();
    RendererPixel(unsigned char red, unsigned char green, unsigned char blue);
    ~RendererPixel();
    void rgb(unsigned char red, unsigned char green, unsigned char blue);
    unsigned char red;
    unsigned char green;
    unsigned char blue;

private:

};

extern RendererPixel WHITE;
extern RendererPixel BLACK;

#endif