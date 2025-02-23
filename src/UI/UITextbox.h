#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Cori {

class UITextbox: public UIElement {
protected:
    sf::Text mText { gUIFont };

    sf::Color mTextColor { sf::Color::Red };
    sf::Color mTextHoverColor { mTextColor };
    sf::Color mTextPressedColor { mTextHoverColor };

    bool centered { false };

    void centerMove();

public:
    UITextbox(float width, float height, const std::string& text, bool transparent = false);
    UITextbox(float x, float y, float width, float height, 
        const std::string& text, bool transparent = false);

    void onHover();
    void onPress();

    //void update();
    void draw(sf::RenderWindow& window);
    
    const std::string getText();
    sf::Text& getRenderText();

    void setText(const std::string& text);

    void setTextColor(const sf::Color color);
    void setTextHoverColor(const sf::Color color);
    void setTextPressedColor(const sf::Color color);

    void centerText();
    void centerTextRelativeTo(UIElement& element);
};

}