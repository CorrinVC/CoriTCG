#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string_view>

namespace Cori {

extern sf::Texture gBlankTexture;
// Global Card Back Texture, Defined in UIImage.cpp
extern sf::Texture gCardBackTexture;

class UIImage: public UIElement {
private:
    sf::Texture mImage;
    sf::Sprite mSprite;
public:
    // Do not include 'res/' in texturepath
    UIImage(float x, float y, const std::string_view texturePath);
    UIImage(float x, float y, sf::Texture texture);

    void draw(sf::RenderWindow& window);

    // Do not include 'res/' in texturepath
    void changeTexture(const std::string_view texturePath);
    void changeTexture(sf::Texture texture);
    
    void setPosition(float x, float y);
    void move(float x, float y);
    void offsetFromOrigin(float xOffset, float yOffset);

    // Scale Uniformly
    void setScale(float scaleFactor);
    // Scale Non-Uniformly
    void setScale(float scaleX, float scaleY);
    void setSize();

    sf::Texture getImage();
    sf::Sprite getSprite();
};

}