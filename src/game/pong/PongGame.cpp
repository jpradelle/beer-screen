#include "PongGame.h"

PongGame::PongGame() : m_paddleLeft(0), m_paddleRight(MATRIX_WIDTH - 1) {

}

PongGame::~PongGame() {

}

void PongGame::nextFrame(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT], IController *controller1, IController *controller2) {
    // Reset matrix
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            matrix[x][y].rgb(0, 0, 0);
        }
    }

    // Move
    m_paddleLeft.move(controller1);
    m_paddleRight.move(controller2);

    // Draw
    m_paddleLeft.draw(matrix);
    m_paddleRight.draw(matrix);
}
