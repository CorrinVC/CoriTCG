#pragma once

#include "States/State.h"
#include <SFML/Graphics.hpp>

namespace Cori {

extern int gWindowWidth;
extern int gWindowHeight;

class Window {
private:

    std::string mTitle {};
    int mWidth {}, mHeight {};

    sf::RenderWindow mWindow {};

    //MenuState menuState {};
    
public:
    Window(std::string_view title, int width, int height);

    void update();
    void draw();
    bool isOpen() const;
    sf::RenderWindow& getRenderWindow();
};

}