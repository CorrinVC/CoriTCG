#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIButton : public UIElement {
//TODO give text & image members
private:
    sf::Text mText { gUIFont };

public:
    UIButton(float x, float y, float width, float height)
    : UIElement(x, y, width, height) {}

    void setText(std::string_view text);
    void setTextColor(sf::Color color);
    void centerText();
    void setBackgroundColor(sf::Color color);

    void draw(sf::RenderWindow& window) override;
};

}