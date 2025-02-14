#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

namespace Cori {

class UIElement {
protected:
    float mX {}, mY {};
    float mWidth {}, mHeight {};

    sf::RectangleShape mRect {};

    //Unique click function
    std::function<void(void)> mClickFunc {};

    bool inBounds(const sf::Vector2i& position);

public:
    UIElement(float x, float y, float width, float height);

    void createClickFunction(std::function<void(void)> func);
    void onClick();

    void update();
    void draw(sf::RenderWindow& window);
};

}