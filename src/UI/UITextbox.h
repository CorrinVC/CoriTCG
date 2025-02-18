#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Cori {

class UITextbox: public UIElement {
protected:
    sf::Text mText { gUIFont };
    bool centered { false };
    UIElement* centeredRelativeTo { nullptr };

    void centerMove();

public:
    UITextbox(float width, float height, const std::string& text, bool transparent = false);
    UITextbox(float x, float y, float width, float height, 
        const std::string& text, bool transparent = false);

    //void update();
    void draw(sf::RenderWindow& window);
    
    const std::string getText();
    sf::Text& getRenderText();

    void setText(const std::string& text);
    void setTextColor(const sf::Color color);
    void centerText();
    void centerTextRelativeTo(UIElement& element);
};

}