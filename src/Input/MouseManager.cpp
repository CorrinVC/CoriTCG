#include "MouseManager.h"
#include "../Window.h"

namespace Cori {

Window* MouseManager::mWindow {};

sf::Vector2i MouseManager::getMousePosition() {
    return sf::Mouse::getPosition((*mWindow).getRenderWindow());
}

}