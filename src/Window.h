#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

class Window {
private:

    std::string mTitle {};
    int mWidth {}, mHeight {};

    sf::RenderWindow mWindow {};

public:
    Window(std::string_view title, unsigned int width, unsigned int height);

    void update();
    void draw();

    int getWidth() const;
    int getHeight() const;
    bool isOpen();
};

}