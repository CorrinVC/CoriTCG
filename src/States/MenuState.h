#pragma once

#include "State.h"

namespace Cori {

class MenuState : public State { // INHERITS STATE CLASS
private:
    UIButton mButton { 100.0f, 200.0f, 100.0f, 100.0f };
public:
    //MenuState() {}

    void init();

    virtual void update() { mButton.update(); }
    virtual void draw(sf::RenderWindow& window) { mButton.draw(window); }
};

}