#include "MouseManager.h"

namespace Cori {

MouseManager gMouseManager {};

// Clear Mouse Input Flags
void MouseManager::resetFlags() {
    if(mMouseLeftPressed) mMouseLeftPressed = false;
    if(mMouseLeftReleased) mMouseLeftReleased = false;
}

void MouseManager::update() {
    resetFlags();
}

void MouseManager::setWindow(sf::RenderWindow& window) {
    sWindow = &window;
}

// Sets Mouse Pressed Flags
void MouseManager::setMouseButtonPressed(sf::Mouse::Button button) {
    switch(button) {
    case sf::Mouse::Button::Left:
        mMouseLeftPressed = true;
        break;
    default: return;
    }
}

// Sets Mouse Release Flags
void MouseManager::setMouseButtonReleased(sf::Mouse::Button button) {
    switch(button) {
    case sf::Mouse::Button::Left: 
        mMouseLeftReleased = true;
        break;
    default: return;
    }
}

// Gets Mouse Position relative to window
sf::Vector2f MouseManager::getMousePosition() {
    return { float(sf::Mouse::getPosition(*sWindow).x), float(sf::Mouse::getPosition(*sWindow).y) };
}

// Checks Button Pressed State
bool MouseManager::getMouseButtonPressed(sf::Mouse::Button button) {
    switch(button) {
    case sf::Mouse::Button::Left: return mMouseLeftPressed;
    default: return false;
    }
}

// Checks Button Released State
bool MouseManager::getMouseButtonReleased(sf::Mouse::Button button) {
    switch(button) {
    case sf::Mouse::Button::Left: return mMouseLeftReleased;
    default: return false;
    }
}

}