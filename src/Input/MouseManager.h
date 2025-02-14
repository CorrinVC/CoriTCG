#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

//class Window;

class MouseManager {
private:
    static sf::RenderWindow* sWindow;

public:
    // Mouse Input Flags
    static bool mouseLeftReleased;

    static void resetFlags();

    static void update();

    // Sets Window for relative mouse position
    static void setWindow(sf::RenderWindow& window);
    static sf::Vector2i getMousePosition();
};

}