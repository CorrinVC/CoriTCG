#include "State.h"
#include "../Window.h"
#include "../Cards/Card.h"

namespace Cori {

State* gCurrentState {};
std::stack<State*> gPreviousStates {};

// If Going Back, Set addToPrevStack to false
void gSetState(State& state, bool addToPrevStack) {
    if(addToPrevStack) gPreviousStates.push(gCurrentState);
    gCurrentState->offSwitch();
    
    gCurrentState = &state;
    gCurrentState->onSwitch();
}

// Top Left Co-ordinate of a Centered Card Image
sf::Vector2f centeredCardPosition() {
    return { 
        gWindowWidth / 2.0f - gCardWidth / 2.0f,
        gWindowHeight / 2.0f - gCardHeight / 2.0f
    };
}

State::~State() {
    // Free UIElement Ptrs
    for(auto* e : mUIElements) {
        delete e;
        e = NULL;
    }
}

void State::onSwitch() {
    if(mOnSwitch != nullptr)
        mOnSwitch();
}

void State::offSwitch() {
    if(mOffSwitch != nullptr)
        mOffSwitch();
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

void State::popUIElement() {
    mUIElements.pop_back();
}

void State::setOnSwitch(std::function<void()> func) {
    mOnSwitch = func;
}

void State::setOffSwitch(std::function<void()> func) {
    mOffSwitch = func;
}

std::vector<UIElement*> State::getElements() {
    return mUIElements;
}

}