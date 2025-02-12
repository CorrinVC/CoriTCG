#pragma once

#include <SFML/Graphics.hpp>

namespace Cori {

//class Window;

class MouseManager {
private:
    static sf::RenderWindow* sWindow;
    
public:
    static void setWindow(sf::RenderWindow& window) { sWindow = &window; }

    static sf::Vector2i getMousePosition();
};

}