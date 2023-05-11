#include "PongGame.h"
#include <iostream>

PongGame::PongGame()
    : m_paddleLeft(0),
        m_paddleRight(MATRIX_WIDTH - 1),
        m_ball(),
        m_started(false),
        m_gameOver(false),
        m_scoreLeft(0),
        m_scoreRight(0) {

}

PongGame::~PongGame() {

}

void PongGame::nextFrame(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT], IController *controller1, IController *controller2, int deltaTime) {
    // Reset matrix
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            matrix[x][y].rgb(0, 0, 0);
        }
    }

    // Move
    m_paddleLeft.move(controller1);
    m_paddleRight.move(controller2);

    if (m_gameOver) {

    } else {
        // Start game ?
        if (controller1->isUp() || controller1->isDown() || controller2->isUp() || controller2->isDown())
            m_started = true;

        if (m_started) {
            m_ball.move(&m_paddleLeft, &m_paddleRight, this, deltaTime);
        }
    }

    // Draw
    m_paddleLeft.draw(matrix);
    m_paddleRight.draw(matrix);
    m_ball.draw(matrix);
}

void PongGame::scoreLeft() {
    m_scoreLeft++;
    if (m_scoreLeft == 9)
        m_gameOver = true;
    std::cout << "Score " << m_scoreLeft << " - " << m_scoreRight << "\n";
    m_ball.start();
}

void PongGame::scoreRight() {
    m_scoreRight++;
    if (m_scoreRight == 9)
        m_gameOver = true;
    std::cout << "Score " << m_scoreLeft << " - " << m_scoreRight << "\n";
    m_ball.start();
}

