#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "conf.h"
#include "renderer/IRenderer.h"
#include "renderer/RendererPixel.h"
#include "renderer/SDL/SDLRenderer.h"
#include "controller/IController.h"
#include "controller/SDL/SDLPlayer1Controller.h"
#include "game/test/TestGame.h"
#include "game/pong/PongGame.h"

int main() {
	IRenderer* renderer = new SDLRenderer();
	IController* player1Controller = new SDLPlayer1Controller();
	IController* player2Controller = new SDLPlayer1Controller(); // TODO
	// IGame* game = new TestGame();
	IGame* game = new PongGame();

	renderer->init();

	RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT];

	int deltaTime = 0;
	while (!player1Controller->isQuit() && !player2Controller->isQuit()) {
		player1Controller->update();
		player2Controller->update();

		game->nextFrame(matrix, player1Controller, player2Controller, deltaTime);

		deltaTime = renderer->draw(matrix);
	}

	renderer->quit();

	delete player1Controller;
	delete player2Controller;
	delete renderer;
	delete game;
	
	return 0;
}

