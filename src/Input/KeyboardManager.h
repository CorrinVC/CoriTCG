#pragma once

#include <SFML/Window.hpp>

namespace Cori {

class KeyboardManager {
private:
    sf::Keyboard::Key mKeyReleased { -1 };

    sf::String mTextInput {};
    bool mAcceptingTextInput { false };
public:
    void update();

    // Key Released Event
    void setKeyReleased(sf::Keyboard::Key keyCode);
    bool keyReleased(sf::Keyboard::Key keyCode);

    // Text Input
    void acceptTextInput(bool accept);
    void appendInput(char32_t c);
    void clearTextInput();

    sf::String& getTextInput();
    bool acceptingTextInput();
};

// Global Keyboard Manager
extern KeyboardManager gKeyboardManager;

}