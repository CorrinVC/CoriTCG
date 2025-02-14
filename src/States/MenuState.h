#pragma once

#include "State.h"
#include "../UI/UIButton.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class MenuState : public State {
private:

    //TEMPORARY -- FIX? DEFINE IN CPP FILE 
    UIButton mButton { 100.0f, 200.0f, 100.0f, 100.0f };

protected:

public:
    virtual void init();

    virtual void update() { 
        //TEMPORARY
        mButton.update(); 
    }

    virtual void draw(sf::RenderWindow& window) { 
        //TEMPORARY
        mButton.draw(window); 
    }
};

}