#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

namespace Cori {

class UIElement {
protected:

    // Original Positions, Used For Offsetting
    float mOriginX {}, mOriginY {};
    float mWidth {}, mHeight {};

    // Bounding rectangle
    sf::RectangleShape mRect {};

    // Background Colors
    sf::Color mBackgroundColor { sf::Color::White };
    sf::Color mHoverColor { mBackgroundColor };
    sf::Color mPressColor { mHoverColor };

    //Unique click function
    std::function<void(void)> mClickFunc {};
    bool mClickFuncCreated { false };

    // Rework to include factors other than element height?
    unsigned int generateUICharSize(float height);

    void updateOrigin(float x, float y);
 
    // Check if position in mRect bounds
    virtual bool inBounds(const sf::Vector2f& position);

    // Hovering & Pressed States
    bool hovering { false };
    bool pressed { false };

public:
    UIElement(float width, float height);
    UIElement(float x, float y, float width, float height);
    virtual ~UIElement() {}

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

    virtual void setPosition(float x, float y);
    // Set relative position functions
    void setPositionRelativeTo(ScreenPosition position, float offset = 0.0f);
    void setPositionRelativeTo(ScreenPosition position, float xOffset, float yOffset);
    void setPositionRelativeTo(const UIElement& element, float xOffset, float yOffset);

    virtual void move(float x, float y);
    void resetToOrigin();
    virtual void offsetFromOrigin(float xOffset, float yOffset);

    // Scale Uniformly
    virtual void setScale(float scaleFactor);
    // Scale Non-Uniformly
    virtual void setScale(float scaleX, float scaleY);
    virtual void setSize(const sf::Vector2f& size);

    void setTransparent();
    void setBackgroundColor(const sf::Color color);
    void setHoverColor(const sf::Color color);
    void setPressedColor(const sf::Color color);

    // Mouse Input Related Behaviour
    void createClickFunction(std::function<void(void)> func);
    void destroyClickFunction();
    virtual void onClick();
    virtual void onHover();
    virtual void onPress();

    virtual void update();
    virtual void draw(sf::RenderWindow& window);

    // Getters
    float getX() const { return mRect.getPosition().x; }
    float getY() const { return mRect.getPosition().y; }
    float getOriginX() const { return mOriginX; }
    float getOriginY() const { return mOriginY; }
    float getWidth() const { return mWidth; }
    float getHeight() const { return mHeight; }

private:
    sf::Vector2f getStartPosition(ScreenPosition position);
};

// Default UI Font, Defined in UIElement.cpp
extern sf::Font gUIFont;

}