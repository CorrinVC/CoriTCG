#pragma once

#include "States/MenuState.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class Window {
private:

    std::string mTitle {};
    int mWidth {}, mHeight {};

    sf::RenderWindow mWindow {};

    State* mCurrentState {};

    MenuState menuState {};
    
public:
    Window(std::string_view title, int width, int height);

    void setState(State* state) { mCurrentState = state; }

    void update();
    void draw();

    int getWidth() const;
    int getHeight() const;
    bool isOpen() const;
    sf::RenderWindow& getRenderWindow();
};

}