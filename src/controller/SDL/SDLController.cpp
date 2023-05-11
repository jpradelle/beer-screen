#include "SDLController.h"


SDLController::SDLController(
        SDL_Scancode mapUp,
        SDL_Scancode mapDown,
        SDL_Scancode mapLeft,
        SDL_Scancode mapRight,
        SDL_Scancode mapButton1,
        SDL_Scancode mapButton2) :
            m_mapUp(mapUp),
            m_mapDown(mapDown),
            m_mapLeft(mapLeft),
            m_mapRight(mapRight),
            m_mapButton1(mapButton1),
            m_mapButton2(mapButton2) {
}

SDLController::~SDLController()
{
}

void SDLController::update() {
    SDL_Event event;

    m_up = false;
    m_down = false;
    m_left = false;
    m_right = false;
    m_button1 = false;
    m_button2 = false;

    const Uint8 * state = SDL_GetKeyboardState(NULL);
    if (state[m_mapUp]) // SDL_SCANCODE_RIGHT
        m_up = true;
    if (state[m_mapDown])
        m_down = true;
    if (state[m_mapLeft])
        m_left = true;
    if (state[m_mapRight])
        m_right = true;
    if (state[m_mapButton1])
        m_button1 = true;
    if (state[m_mapButton2])
        m_button2 = true;

    // Events management
    while (SDL_PollEvent(&event)) {
        switch (event.type) {

        case SDL_QUIT:
            // handling of close button
            m_quit = true;
            break;

        // case SDL_KEYDOWN:
        //     SDL_Scancode code = event.key.keysym.scancode;
        //     if (code == m_mapUp) {
        //         m_up = true;
        //     } else if (code == m_mapDown) {
        //         m_down = true;
        //     } else if (code == m_mapLeft) {
        //         m_left = true;
        //     } else if (code == m_mapRight) {
        //         m_right = true;
        //     } else if (code == m_mapButton1) {
        //         m_button1 = true;
        //     } else if (code == m_mapButton2) {
        //         m_button2 = true;
        //     }
        }
    }
}

bool SDLController::isUp() {
    return m_up;
}

bool SDLController::isDown() {
    return m_down;
}

bool SDLController::isLeft() {
    return m_left;
}

bool SDLController::isRight() {
    return m_right;
}

bool SDLController::isButton1() {
    return m_button1;
}

bool SDLController::isButton2() {
    return m_button2;
}

bool SDLController::isQuit() {
    return m_quit;
}
