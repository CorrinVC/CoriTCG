#include "UIProfilePicture.h"
#include "../Cards/Card.h"

namespace Cori {

UIProfilePicture::UIProfilePicture(const sf::Texture* texture, float x, float y) 
: UIElement(x, y, 300.0f, 300.0f)
, mTexture { texture }
{
    updateTexture();
}

void UIProfilePicture::updateTexture() {
    mCircle.setTexture(mTexture);
    mCircle.setTextureRect({{ int(gCardWidth / 2.0f) - 150, 175 }, { 300, 300 }});
}

void UIProfilePicture::draw(sf::RenderWindow& window) {
    window.draw(mCircle);
}

void UIProfilePicture::changeTexture(const sf::Texture* texture) {
    mTexture = texture;
    updateTexture();
    setPosition(getX(), getY());
}

void UIProfilePicture::setPosition(float x, float y) {
    mCircle.setPosition({ x, y });
    UIElement::setPosition(x, y);
}

}