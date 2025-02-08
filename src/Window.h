#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

class Window {
private:

    std::string mTitle;
    unsigned int mWidth, mHeight;

    sf::RenderWindow mWindow;

public:
    Window(std::string_view title, unsigned int width, unsigned int height);

    void update();
    void draw();

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    bool isOpen();
};

}