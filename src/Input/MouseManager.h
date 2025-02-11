#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

class Window;

class MouseManager {
private:
    static Window* mWindow;
    
public:
    static void setWindow(Window& window) { mWindow = &window; }

    static sf::Vector2i getMousePosition();
};

}