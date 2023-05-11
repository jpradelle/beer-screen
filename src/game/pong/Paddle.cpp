#include "Paddle.h"

Paddle::Paddle(int x) : m_x(x), m_y((MATRIX_HEIGHT - PADDLE_HEIGHT) / 2) {

}

Paddle::~Paddle() {

}

void Paddle::move(IController *controller) {
    if (controller->isDown())
        m_y++;
    if (controller->isUp())
        m_y--;
    
    if (m_y < 0)
        m_y = 0;
    if (m_y + PADDLE_HEIGHT >= MATRIX_HEIGHT)
        m_y = MATRIX_HEIGHT - PADDLE_HEIGHT;
}

void Paddle::draw(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT]) {
    for (int y = m_y; y < m_y + PADDLE_HEIGHT; y++) {
        matrix[m_x][y].rgb(255, 255, 255);
    }
}

int Paddle::getX() const {
    return m_x;
}

int Paddle::getY() const {
    return m_y;
}

int Paddle::getHeight() const {
    return PADDLE_HEIGHT;
}
