#pragma once

#include "../UI/UIElement.h"
#include <vector>

namespace Cori {

class State {
private:
    //static inline int sID { 0 };
    static State* sCurrentState;
    std::vector<UIElement> uiElements;

public:
    static void setState(State& state) { sCurrentState = &state; }
    //static void setState(State* state) { sCurrentState = state; }

    static State* getState() { return sCurrentState; }

    void update();
    void draw(sf::RenderWindow& window);
};

}