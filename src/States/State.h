#pragma once

//#include "../UI/UIElement.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class State {
public:
    
    virtual void init() {};
    
    virtual void update();
    virtual void draw(sf::RenderWindow& window);
};

}