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
    for (std::vector<UIElement*>::reverse_iterator elements = mUIElements.rbegin();
            elements != mUIElements.rend(); ++elements) {
        (*elements)->update();
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