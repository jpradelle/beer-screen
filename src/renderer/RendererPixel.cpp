#include "RendererPixel.h"

RendererPixel WHITE(255, 255, 255);
RendererPixel BLACK(0, 0, 0);

RendererPixel::RendererPixel() : red(0), green(0), blue(0) {

}

RendererPixel::RendererPixel(unsigned char _red, unsigned char _green, unsigned char _blue) : red(_red), green(_green), blue(_blue) {

}


RendererPixel::~RendererPixel() {

}

void RendererPixel::rgb(unsigned char red, unsigned char green, unsigned char blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}
