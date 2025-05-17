#include "KeyboardManager.h"
#include <iostream>

namespace Cori {

KeyboardManager gKeyboardManager {};

void KeyboardManager::update() {
    if(mKeyReleased == sf::Keyboard::Key::Left && mInputPosition > 0) --mInputPosition;
    else if(mKeyReleased == sf::Keyboard::Key::Right 
        && mInputPosition < mTextInput.getSize()) ++mInputPosition; 

    mKeyReleased = sf::Keyboard::Key(-1);
}

void KeyboardManager::setKeyReleased(sf::Keyboard::Key keyCode) {
    mKeyReleased = keyCode;
}

bool KeyboardManager::keyReleased(sf::Keyboard::Key keyCode) {
    return keyCode == mKeyReleased;
}

void KeyboardManager::acceptTextInputFrom(UITextField* textField) {
    mCurrentTextField = textField;
}

bool KeyboardManager::filterChar(char32_t c) {
    bool acceptable { true };
    switch(c) {
    case 8:
        if(mTextInput.getSize() > 0 && mInputPosition > 0) {
            mTextInput.erase(-1 + mInputPosition--);
        }
        acceptable = false;
        break;
    case 9: case 10: case 13:
        acceptable = false;
        break;
    case 127:
        if(mTextInput.getSize() > mInputPosition)
            mTextInput.erase(mInputPosition);
        acceptable = false;
        break;
    }
    return acceptable;
}

void KeyboardManager::appendInput(char32_t c) {
    if(filterChar(c)) {
        //mTextInput += c;
        mTextInput.insert(mInputPosition++, c);
        //++mInputPosition;
    }
}

void KeyboardManager::clearTextInput() {
    mTextInput = {};
    mInputPosition = 0;
}

sf::String& KeyboardManager::getTextInput() {
    return mTextInput;
}

UITextField* KeyboardManager::currentTextField() {
    return mCurrentTextField;
}

std::size_t KeyboardManager::getInputPosition() {
    return mInputPosition;
}
    
}