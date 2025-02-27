#include "State.h"

namespace Cori {

State* gCurrentState {};

void gSetState(State& state) {
    gCurrentState = &state;
}

State::~State() {
    // Free UIElement Ptrs
    for(auto* e : mUIElements) {
        delete e;
    }
}

void State::update() { 
    // Update UIElements
    for (auto* e : mUIElements) {
        e->update();
    }
}

void State::draw(sf::RenderWindow& window) {
    // Render UIElements
    for(auto* e : mUIElements) {
        e->draw(window);
    }
}

void State::addUIElement(UIElement* e) {
    mUIElements.push_back(e);
}

}