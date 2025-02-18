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
    UIImage(float x, float y, std::string_view texturePath);

    void draw(sf::RenderWindow& window);
};

}