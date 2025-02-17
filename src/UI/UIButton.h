#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIButton : public UIElement {
//TODO give text & image members
private:
    sf::Text mText { gUIFont };

public:
    UIButton(float width, float height)
    : UIElement(width, height) {}
    UIButton(float x, float y, float width, float height)
    : UIElement(x, y, width, height) {}

    void setText(const std::string_view text);
    void setTextColor(const sf::Color color);
    void centerText();

    void draw(sf::RenderWindow& window) override;
};

}