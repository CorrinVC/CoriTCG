#include "KeyboardManager.h"
#include <iostream>

namespace Cori {

KeyboardManager gKeyboardManager {};

void KeyboardManager::update() {
    mKeyReleased = sf::Keyboard::Key(-1);
}

void KeyboardManager::setKeyReleased(sf::Keyboard::Key keyCode) {
    mKeyReleased = keyCode;
}

bool KeyboardManager::keyReleased(sf::Keyboard::Key keyCode) {
    return keyCode == mKeyReleased;
}

void KeyboardManager::acceptTextInput(bool accept) {
    mAcceptingTextInput = accept;
}

void KeyboardManager::appendInput(char32_t c) {
    mTextInput += c;
    std::cout << mTextInput.toAnsiString() << std::endl;
}

void KeyboardManager::clearTextInput() {
    mTextInput = {};
}

bool KeyboardManager::acceptingTextInput() {
    return mAcceptingTextInput;
}

sf::String& KeyboardManager::getTextInput() {
    return mTextInput;
}
    
}