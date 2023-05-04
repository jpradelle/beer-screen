#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "renderer/IRenderer.h"
#include "renderer/SDL/SDLRenderer.h"

int main() {
	IRenderer* renderer = new SDLRenderer();

	renderer->init();
		
	return 0;
}

