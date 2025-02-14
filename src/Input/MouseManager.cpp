#include "MouseManager.h"
#include <iostream>

namespace Cori {

sf::RenderWindow* MouseManager::sWindow {};
bool MouseManager::mouseLeftReleased { false };

// Clear Mouse Input Flags
void MouseManager::resetFlags() {
    if(mouseLeftReleased) mouseLeftReleased = false;
}

void MouseManager::update() {
    resetFlags();
}

void MouseManager::setWindow(sf::RenderWindow& window) {
    sWindow = &window;
}

// Gets Mouse Position relative to window
sf::Vector2i MouseManager::getMousePosition() {
    return sf::Mouse::getPosition(*sWindow);
}

/*bool MouseManager::getMouseButtonReleased(sf::Mouse::Button button) {
    switch(button) {
    case sf::Mouse::Button::Left: return sMouseLeftReleased;
    default: return false;
    }
}*/

}