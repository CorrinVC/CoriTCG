#include "State.h"

namespace Cori {

State State::sCurrentState {};

void State::update() { }

void State::draw(sf::RenderWindow& window) {
    window.draw(sf::CircleShape(100.0f));
}

}