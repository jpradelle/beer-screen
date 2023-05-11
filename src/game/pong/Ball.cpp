#include "Ball.h"
#include <math.h>
#include "PongGame.h"
#include <iostream>

Ball::Ball() : m_x(MATRIX_WIDTH / 2), m_y(MATRIX_HEIGHT / 2), m_speed(20), m_angle(0) {

}

Ball::~Ball() {

}

void Ball::move(Paddle *paddleLeft, Paddle *paddleRight, PongGame* game, int deltaTime) {
    m_x += m_speed * deltaTime / 1000.0; // TODO
    m_y += 0;

    int x = round(m_x);
    int y = round(m_y);
    if (x <= paddleLeft->getX()) {
        if (y >= paddleLeft->getY() && y <= paddleLeft->getY() + paddleRight->getHeight()) {
            // Collide width paddle
            m_speed *= -1;
        } else {
            // Out
            game->scoreRight();
        }
    }
    if (x >= paddleRight->getX()) {
        if (y >= paddleRight->getY() && y <= paddleRight->getY() + paddleRight->getHeight()) {
            // Collide width paddle
            m_speed *= -1;
        } else {
            // Out
            game->scoreLeft();
        }
    }
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
