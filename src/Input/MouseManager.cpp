#include "MouseManager.h"

namespace Cori {

MouseManager gMouseManager {};

// Clear Mouse Input Flags
void MouseManager::resetFlags() {
    if(mMouseLeftPressed && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
        mMouseLeftPressed = false;
    if(mMouseLeftReleased) mMouseLeftReleased = false;
}

void MouseManager::update() {
    resetFlags();
}

void MouseManager::setWindow(sf::RenderWindow& window) {
    mWindow = &window;
}

// Sets In View Var, Defaults to True
void MouseManager::setInView(bool inView) {
    mInView = inView;
}

// Use setInView(false) to set out of view
void MouseManager::setInView(sf::View& view) {
    setInView();
    mView = &view;
}

void MouseManager::fillPressedSlot(UIElement* slot) {
    std::cout << slot << " filled" << std::endl;
    mPressedSlot = slot;
}

void MouseManager::clearPressedSlot() {
    if(mPressedSlot == nullptr) return;
    std::cout << mPressedSlot << " cleared " << std::endl;
    mPressedSlot = nullptr;
}

bool MouseManager::pressSlotCleared() {
    return mPressedSlot == nullptr;
}

bool MouseManager::checkPressedSlot(UIElement* checked) {
    return mPressedSlot == checked || pressSlotCleared();
}

// Sets Mouse Pressed Flags
void MouseManager::setMouseButtonPressed(sf::Mouse::Button button, bool pressed) {
    switch(button) {
    case sf::Mouse::Button::Left:
        mMouseLeftPressed = pressed;
        break;
    default: return;
    }
}

// Sets Mouse Release Flags
void MouseManager::setMouseButtonReleased(sf::Mouse::Button button, bool released) {
    switch(button) {
    case sf::Mouse::Button::Left: 
        mMouseLeftReleased = released;
        break;
    default: return;
    }
}

// Gets Mouse Position relative to window
sf::Vector2f MouseManager::getMousePosition() {
    if(mInView)
        return mWindow->mapPixelToCoords(sf::Mouse::getPosition(*mWindow), *mView);
    else
        return { float(sf::Mouse::getPosition(*mWindow).x), float(sf::Mouse::getPosition(*mWindow).y) };
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