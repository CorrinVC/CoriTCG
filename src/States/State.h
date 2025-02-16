#pragma once

#include "../UI/UIElement.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Cori {

class State {
private:
    std::vector<UIElement*> mUIElements {};
public:    
    void update();
    void draw(sf::RenderWindow& window);

    void addUIElement(UIElement* e);
};

extern State gMenuState;
extern void initMenuState();

}