#include "Ball.h"
#include <math.h>

Ball::Ball() : m_x(MATRIX_WIDTH / 2), m_y(MATRIX_HEIGHT / 2), m_speed(10), m_angle(0) {

}

Ball::~Ball() {

}

void Ball::move(Paddle *paddleLeft, Paddle *paddleRight, int deltaTime) {
    m_x += m_speed * deltaTime / 1000; // TODO
    m_y += 0;
}

void Ball::draw(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT]) {
    int x = round(m_x);
    int y = round(m_y);
    matrix[x][y].rgb(255, 255, 255);
}
