#pragma once

#include <SFML/System.hpp>

namespace Cori {

class KeyboardManager {
private:
    sf::String mTextInput {};
    bool mAcceptingTextInput { false };
public:
    void update();

    void acceptTextInput(bool accept);
    void appendInput(char32_t c);
    void clearTextInput();

    sf::String& getTextInput();
    bool acceptingTextInput();
};

// Global Keyboard Manager
extern KeyboardManager gKeyboardManager;

}