#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Cori {

class UITextbox: public UIElement {
protected:
    sf::Text mText { gUIFont };

    // Text Colors
    sf::Color mTextColor { sf::Color::Red };
    sf::Color mTextHoverColor { mTextColor };
    sf::Color mTextPressedColor { mTextHoverColor };

    bool centered { false };

    // Text Centering Helper Function
    // initial - whether this function is called in constructor or not; default = false
    void centerMove(bool initial = false);

public:
    UITextbox();
    UITextbox(float width, float height, const std::string text, bool transparent = false);
    UITextbox(float x, float y, float width, float height, 
        const std::string text, bool transparent = false);

    // Mouse Behaviour Functionality
    void onHover();
    void onPress();

    void draw(sf::RenderWindow& window);
    
    const std::string getText();
    sf::Text& getRenderText(); // Remove? Currently Unused

    void setText(const sf::String text);

    void setTextColor(const sf::Color color);
    void setTextHoverColor(const sf::Color color);
    void setTextPressedColor(const sf::Color color);

    void setPosition(float x, float y) override;
    void offsetFromOrigin(float xOffset, float yOffset) override;
    void setScale(float scaleX, float scaleY) override;

    // Text Centering Functions
    void centerText();
    void centerTextRelativeTo(UIElement& element);
};

}