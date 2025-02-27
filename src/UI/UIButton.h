#pragma once

#include "UIElement.h"
#include "UITextbox.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Cori {

class UIButton : public UIElement {
//TODO give text & image members
private:
    // change to uitextbox
    UITextbox mTextbox;

public:
    UIButton(float width, float height);
    UIButton(float x, float y, float width, float height);

    void update();
    void draw(sf::RenderWindow& window) override;

    // Write Wrapper Functions
    UITextbox& getTextbox();
};

}