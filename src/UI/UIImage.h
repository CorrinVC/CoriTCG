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

    void draw(sf::RenderWindow& window);

    // Do not include 'res/' in texturepath
    void changeTexture(const std::string_view texturePath);
};

}