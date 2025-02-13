#pragma once

#include "../UI/UIButton.h"

namespace Cori {

class State {

protected:
    //std::vector<UIElement> uiElements {};

    virtual void init() {}

public:
    //static void setState(State* state) { sCurrentState = state; }

    //static State* getState() { return sCurrentState; }

    virtual void update();
    virtual void draw(sf::RenderWindow& window);
};

}