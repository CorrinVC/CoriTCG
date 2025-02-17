#include "State.h"

namespace Cori {

State* gCurrentState {};

void gSetState(State& state) {
    gCurrentState = &state;
}

void State::update() { 
    for (auto* e : mUIElements) {
        e->update();
    }
}

void State::draw(sf::RenderWindow& window) {
    for(auto* e : mUIElements) {
        e->draw(window);
    }
}

void State::addUIElement(UIElement* e) {
    mUIElements.push_back(e);
}

}