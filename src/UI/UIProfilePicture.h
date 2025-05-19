#pragma once

#include "UIElement.h"
#include <SFML/Graphics.hpp>

namespace Cori {

class UIProfilePicture : public UIElement {
private:
    sf::CircleShape mCircle { 150.0f };
    const sf::Texture* mTexture;

    void updateTexture();
public:
    UIProfilePicture(const sf::Texture* texture, float x = 0.0f, float y = 0.0f);

    void draw(sf::RenderWindow& window);

    void changeTexture(const sf::Texture* texture);
    void setPosition(float x, float y) override;
};

}