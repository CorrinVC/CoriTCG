#include "MouseManager.h"

namespace Cori {

sf::RenderWindow* MouseManager::sWindow {};

sf::Vector2i MouseManager::getMousePosition() {
    return sf::Mouse::getPosition(*sWindow);
}

}