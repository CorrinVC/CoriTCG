#pragma once

#include "../Window.h"

namespace Cori {

class State {
private:
    //static inline int sID { 0 };
    static State sCurrentState;

public:
    static void setState(const State& state) { sCurrentState = state; }
    static State& getState() { return sCurrentState; }

    void update();
    void draw(sf::RenderWindow& window);
};

}