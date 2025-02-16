#include "MouseManager.h"
#include <iostream>

namespace Cori {

MouseManager gMouseManager {};

// Clear Mouse Input Flags
void MouseManager::resetFlags() {
    if(mMouseLeftReleased) mMouseLeftReleased = false;
}

void MouseManager::update() {
    resetFlags();
}

void MouseManager::setWindow(sf::RenderWindow& window) {
    sWindow = &window;
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
sf::Vector2i MouseManager::getMousePosition() {
    return sf::Mouse::getPosition(*sWindow);
}

// Checks Button Released State
bool MouseManager::getMouseButtonReleased(sf::Mouse::Button button) {
    switch(button) {
    case sf::Mouse::Button::Left: return mMouseLeftReleased;
    default: return false;
    }
}

}