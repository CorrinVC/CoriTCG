#pragma once

#include "States/State.h"
#include <SFML/Graphics.hpp>

namespace Cori {

constexpr inline int gWindowWidth { 1200 };
constexpr inline int gWindowHeight { 900 };

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