#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

class Window {
private:

    std::string mTitle {};
    int mWidth {}, mHeight {};

    sf::RenderWindow mWindow {};

public:
    Window(std::string_view title, int width, int height);

    void update();
    void draw();

    int getWidth() const { return mWidth; }
    int getHeight() const { return mHeight; }
    bool isOpen() const { return mWindow.isOpen(); }
};

}