#include "SDLRenderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

SDLRenderer::SDLRenderer()
{

}

SDLRenderer::~SDLRenderer()
{

}

void SDLRenderer::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error initializing SDL: %s\n", SDL_GetError());
	
	m_win = SDL_CreateWindow(
            "GAME", // creates a window
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1000,
            1000,
            0);
 
	// triggers the program that controls
	// your graphics hardware and sets flags
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
 
	// creates a renderer to render our images
	SDL_Renderer* rend = SDL_CreateRenderer(m_win, -1, render_flags);
 
	// let us control our image position
	// so that we can move it with our keyboard.
	SDL_Rect dest;
 
	// adjust height and width of our image box.
	dest.w = 20;
	dest.h = 20;
 
	// sets initial x-position of object
	dest.x = (1000 - dest.w) / 2;
 
	// sets initial y-position of object
	dest.y = (1000 - dest.h) / 2;
 
	// controls animation loop
	int close = 0;
 
	// speed of box
	int speed = 300;
 
	// animation loop
	while (!close) {
		SDL_Event event;
 
		// Events management
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
 
			case SDL_QUIT:
				// handling of close button
				close = 1;
				break;
 
			case SDL_KEYDOWN:
				// keyboard API for key pressed
				switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					dest.y -= speed / 30;
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					dest.x -= speed / 30;
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					dest.y += speed / 30;
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					dest.x += speed / 30;
					break;
				default:
					break;
				}
			}
		}
 
		// right boundary
		if (dest.x + dest.w > 1000)
			dest.x = 1000 - dest.w;
 
		// left boundary
		if (dest.x < 0)
			dest.x = 0;
 
		// bottom boundary
		if (dest.y + dest.h > 1000)
			dest.y = 1000 - dest.h;
 
		// upper boundary
		if (dest.y < 0)
			dest.y = 0;
 
		// clears the screen
		SDL_RenderClear(rend);
		
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		SDL_RenderDrawRect(rend, &dest);
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
 
		// triggers the double buffers
		// for multiple rendering
		SDL_RenderPresent(rend);
 
		// calculates to 60 fps
		SDL_Delay(1000 / 60);
	}
 
	// destroy renderer
	SDL_DestroyRenderer(rend);
 
	// destroy window
	SDL_DestroyWindow(m_win);
	 
	// close SDL
	SDL_Quit();
}

void SDLRenderer::draw(RendererPixel **pixels)
{
}
