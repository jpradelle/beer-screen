#include "SDLRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

SDLRenderer::SDLRenderer() : m_lastRender(0) {

}

SDLRenderer::~SDLRenderer() {

}

void SDLRenderer::init() {
	std::cout << "OK\n";
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error initializing SDL: %s\n", SDL_GetError());
	
	m_win = SDL_CreateWindow(
            "GAME", // creates a window
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            (PIXEL_SIZE + PIXEL_MARGIN) * MATRIX_WIDTH,
            (PIXEL_SIZE + PIXEL_MARGIN) * MATRIX_HEIGHT,
            0);
 
	// creates a renderer to render our images
	m_rend = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);

	for (int x = 0; x < MATRIX_WIDTH; x++) {
		for (int y = 0; y < MATRIX_HEIGHT; y++) {
			m_pixels[x][y].x = x * (PIXEL_SIZE + PIXEL_MARGIN);
			m_pixels[x][y].y = y * (PIXEL_SIZE + PIXEL_MARGIN);
			m_pixels[x][y].w = PIXEL_SIZE;
			m_pixels[x][y].h = PIXEL_SIZE;
		}
	}
}

int SDLRenderer::draw(RendererPixel pixels[MATRIX_WIDTH][MATRIX_HEIGHT]) {
	SDL_RenderClear(m_rend);

	for (int x = 0; x < MATRIX_WIDTH; x++) {
		for (int y = 0; y < MATRIX_HEIGHT; y++) {
			SDL_SetRenderDrawColor(m_rend, pixels[x][y].red, pixels[x][y].green, pixels[x][y].blue, 255);
			// SDL_RenderFillRect(m_rend, &m_pixels[x][y]);
			SDL_RenderFillCircle(m_rend, m_pixels[x][y].x + PIXEL_SIZE / 2, m_pixels[x][y].y + PIXEL_SIZE / 2, PIXEL_SIZE / 2);
		}
	}

	SDL_SetRenderDrawColor(m_rend, 0, 0, 0, 255);
	SDL_RenderPresent(m_rend);

	// calculates to 30 fps
    if (m_lastRender == 0) {
	    SDL_Delay(1000 / 30);
        m_lastRender = SDL_GetTicks();
    } else {
        int delay = (int) ((Uint32) (1000 / 30) - (SDL_GetTicks() - m_lastRender));
        std::cout << "sleep(" << delay << ")" << std::endl;
        if (delay > 0)
	        SDL_Delay(delay);

        Uint32 time = SDL_GetTicks();
        Uint32 elapsedTime = time - m_lastRender;
        m_lastRender = time;
        std::cout << "sleep(" << delay << ", " << elapsedTime << ")" << std::endl;

        return (int) elapsedTime;
    }

    return 1;
}

void SDLRenderer::quit() {
	SDL_DestroyRenderer(m_rend);
	SDL_DestroyWindow(m_win);
	SDL_Quit();
}

int SDLRenderer::SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius) {
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx, x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety, x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety, x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx, x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        } else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        } else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}
