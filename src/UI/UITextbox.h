#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UITextbox: public UIElement {
private:
    sf::Text mText { gUIFont };
    std::string** mTextString;

public:
    UITextbox(float width, float height, std::string** text, bool transparent = false);
    UITextbox(float x, float y, float width, float height,
            std::string** text, bool transparent = false);

    void update();
    void draw(sf::RenderWindow& window);

};

}