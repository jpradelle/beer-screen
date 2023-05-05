#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "conf.h"
#include "renderer/IRenderer.h"
#include "renderer/RendererPixel.h"
#include "renderer/SDL/SDLRenderer.h"
#include "controller/IController.h"
#include "controller/SDL/SDLPlayer1Controller.h"

int main() {
	IRenderer* renderer = new SDLRenderer();
	IController* player1Controller = new SDLPlayer1Controller();

	renderer->init();

	RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT];
	int xPlayer = MATRIX_WIDTH / 2;
	int yPlayer = MATRIX_HEIGHT / 2;

	while (!player1Controller->isQuit()) {
		player1Controller->update();

		// Reset matrix
		for (int x = 0; x < MATRIX_WIDTH; x++) {
			for (int y = 0; y < MATRIX_HEIGHT; y++) {
				matrix[x][y].rgb(0, 0, 0);
			}
		}

		// Move stuff
		if (player1Controller->isRight())
			xPlayer += 1;
		if (player1Controller->isLeft())
			xPlayer -= 1;
		if (player1Controller->isDown())
			yPlayer += 1;
		if (player1Controller->isUp())
			yPlayer -= 1;
		
		if (xPlayer < 0)
			xPlayer = 0;
		else if (xPlayer >= MATRIX_WIDTH)
			xPlayer = MATRIX_WIDTH - 1;
		if (yPlayer < 0)
			yPlayer = 0;
		else if (yPlayer >= MATRIX_HEIGHT)
			yPlayer = MATRIX_HEIGHT - 1;

		matrix[xPlayer][yPlayer].rgb(255, 255, 255);

		renderer->draw(matrix);
	}

	renderer->quit();

	delete player1Controller;
	delete renderer;
	
	return 0;
}

