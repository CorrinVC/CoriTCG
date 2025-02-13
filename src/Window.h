#pragma once

#include "States/MenuState.h"

namespace Cori {

class Window {
private:

    std::string mTitle {};
    int mWidth {}, mHeight {};

    sf::RenderWindow mWindow {};

    State* mCurrentState = new State {};

    MenuState menuState {};
    
public:
    Window(std::string_view title, int width, int height);

    void setState(State* state) { mCurrentState = state; }

    void update();
    void draw();

    int getWidth() const { return mWidth; }
    int getHeight() const { return mHeight; }
    bool isOpen() const { return mWindow.isOpen(); }
    sf::RenderWindow& getRenderWindow() { return mWindow; }
};

}