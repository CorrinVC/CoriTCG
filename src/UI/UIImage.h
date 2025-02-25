#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <string_view>

namespace Cori {

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
    void setScale(float scaleFactor);
    void setScale(float scaleX, float scaleY);
};

}