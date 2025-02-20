#pragma once

#include "States/State.h"
#include <SFML/Graphics.hpp>

namespace Cori {

constexpr int gWindowWidth { 1300 };
constexpr int gWindowHeight { 1000 };

class Window {
private:

    const std::string mTitle {};
    const int mWidth {}, mHeight {};

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