#include "TestGame.h"

TestGame::TestGame() : m_x(MATRIX_WIDTH / 2), m_y(MATRIX_HEIGHT / 2) {

}

TestGame::~TestGame() {

}

void TestGame::nextFrame(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT], IController *controller1, IController *controller2) {
    // Reset matrix
    for (int x = 0; x < MATRIX_WIDTH; x++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            matrix[x][y].rgb(0, 0, 0);
        }
    }

    // Move stuff
    if (controller1->isRight())
        m_x += 1;
    if (controller1->isLeft())
        m_x -= 1;
    if (controller1->isDown())
        m_y += 1;
    if (controller1->isUp())
        m_y -= 1;
    
    if (m_x < 0)
        m_x = 0;
    else if (m_x >= MATRIX_WIDTH)
        m_x = MATRIX_WIDTH - 1;
    if (m_y < 0)
        m_y = 0;
    else if (m_y >= MATRIX_HEIGHT)
        m_y = MATRIX_HEIGHT - 1;

    matrix[m_x][m_y].rgb(255, 255, 255);
}
