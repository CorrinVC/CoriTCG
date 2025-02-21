#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

namespace Cori {

class UIElement {
protected:

    float mWidth {}, mHeight {};

    // Bounding rectangle
    sf::RectangleShape mRect {};

    //Unique click function
    std::function<void(void)> mClickFunc {};
 
    // Check if position in mRect bounds
    virtual bool inBounds(const sf::Vector2i& position);

public:
    UIElement(float width, float height);
    UIElement(float x, float y, float width, float height);

    // Used in relative position functions
    enum ScreenPosition {
        ScreenTop,
        ScreenTopRight,
        ScreenLeft,
        ScreenCenter,
        ScreenRight,
        ScreenBottomLeft,
        ScreenBottom,
        ScreenBottomRight,
    };

    // Set relative position functions
    void setPositionRelativeTo(ScreenPosition position, float offset = 0.0f);
    void setPositionRelativeTo(ScreenPosition position, float xOffset, float yOffset);
    void setPositionRelativeTo(const UIElement& element, float xOffset, float yOffset);

    void setSize(const sf::Vector2f& size);

    void setBackgroundColor(const sf::Color color);
    // On Click behaviour
    void createClickFunction(std::function<void(void)> func);
    virtual void onClick();

    virtual void update();
    virtual void draw(sf::RenderWindow& window);

    // Getters
    float getX() const { return mRect.getPosition().x; }
    float getY() const { return mRect.getPosition().y; }

private:
    sf::Vector2f getStartPosition(ScreenPosition position);
};

extern sf::Font gUIFont;

unsigned int generateUICharSize(float height);

}