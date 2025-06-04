#pragma once

#include "UIElement.h"
#include "UITextbox.h"

namespace Cori {

class UICheckbox : public UIElement {
private:
    bool mChecked { false };
    UITextbox mText;

    sf::RectangleShape mCheckSymbol;
    void updateCheckSymbol();
public:
    UICheckbox(float x, float y, float width, float height, sf::String text);
    UICheckbox(float width, float height, sf::String text);

    void update();
    void draw(sf::RenderWindow& window);
};

}