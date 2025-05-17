#pragma once

#include <SFML/Window.hpp>
#include "../UI/UITextField.h"

namespace Cori {

class KeyboardManager {
private:
    sf::Keyboard::Key mKeyReleased { -1 };

    sf::String mTextInput {};
    bool mAcceptingTextInput { false };
    UITextField* mCurrentTextField { nullptr };

    bool filterChar(char32_t c);
    std::size_t mInputPosition {};
    
public:
    void update();

    // Key Released Event
    void setKeyReleased(sf::Keyboard::Key keyCode);
    bool keyReleased(sf::Keyboard::Key keyCode);

    // Text Input
    void acceptTextInputFrom(UITextField* textField);
    void appendInput(char32_t c);
    void clearTextInput();

    sf::String& getTextInput();
    UITextField* currentTextField();
    std::size_t getInputPosition();
};

// Global Keyboard Manager
extern KeyboardManager gKeyboardManager;

}