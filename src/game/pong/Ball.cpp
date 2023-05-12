#include "Ball.h"
#include <math.h>
#include "PongGame.h"
#include <iostream>

Ball::Ball() : m_x(MATRIX_WIDTH / 2), m_y(MATRIX_HEIGHT / 2), m_speed(40), m_angle(M_PI / 8) {

}

Ball::~Ball() {

}

void Ball::move(Paddle *paddleLeft, Paddle *paddleRight, PongGame* game, int deltaTime) {
    float dx = m_speed * deltaTime / 1000.0 * cos(m_angle);
    float dy = m_speed * deltaTime / 1000.0 * sin(m_angle);

    if (m_x + dx <= paddleLeft->getX() + 1 && m_y >= paddleLeft->getY() - 0.5 && m_y <= paddleLeft->getY() + paddleRight->getHeight() + 0.5) {
        // Collide width paddle
        m_angle = M_PI - m_angle;
        m_x = paddleLeft->getX() + 1;
    } else if (m_x + dx <= 0) {
        // Out
        game->scoreRight();
    } else if (m_x + dx >= paddleRight->getX() - 1 && m_y >= paddleRight->getY() - 0.5 && m_y <= paddleRight->getY() + paddleRight->getHeight() + 0.5) {
        // Collide width paddle
        m_angle = M_PI - m_angle;
        m_x = paddleRight->getX() - 1;
    } else if (m_x + dx >= MATRIX_WIDTH - 1) {
        // Out
        game->scoreLeft();
    } else {
        m_x += dx;
    }

    if (m_y + dy <= 0) {
        m_angle *= -1;
        m_y -= dy;
    } else if (m_y >= MATRIX_HEIGHT - 1) {
        m_angle *= -1;
        m_y -= dy;
    } else {
        m_y += dy;
    }

    if (m_x < 0)
        m_x = 0;
    if (m_x > MATRIX_WIDTH - 1)
        m_x = MATRIX_WIDTH - 1;

    if (m_y < 0)
        m_y = 0;
    if (m_y > MATRIX_HEIGHT - 1)
        m_y = MATRIX_HEIGHT - 1;
}

void Ball::draw(RendererPixel matrix[MATRIX_WIDTH][MATRIX_HEIGHT]) {
    int x = round(m_x);
    int y = round(m_y);
    matrix[x][y].rgb(255, 0, 0);
}

void Ball::start() {
    m_x = MATRIX_WIDTH / 2;
    m_y = MATRIX_HEIGHT / 2;
}
