#pragma once

#include "UITextbox.h"
#include <SFML/Graphics.hpp>
//#include <stddef.h>

namespace Cori {

class UITextField : public UITextbox {
private:
    bool mHighlighted { false };
    
    sf::Text mCursor { gUIFont };
    void updateCursor();

public:
    UITextField(float width, float height, bool transparent = false);
    UITextField(float x, float y, float width, float height, bool transparent = false);

    //void onClick() override;

    void update() override;
    void draw(sf::RenderWindow& window) override;
    //void draw(sf::RenderWindow& window);

    sf::String getTextInput();
    sf::String flushTextInput();
};


}