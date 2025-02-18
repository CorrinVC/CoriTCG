#include "UIImage.h"

namespace Cori {

UIImage::UIImage(float x, float y, std::string_view texturePath)
: UIElement(x, y, 0.0f, 0.0f)
, mImage { texturePath }
, mSprite { mImage }
{
    setSize({ 
        static_cast<float>(mImage.getSize().x), 
        static_cast<float>(mImage.getSize().y)
    });
    mSprite.setPosition({ x, y });
}

void UIImage::draw(sf::RenderWindow& window) {
    window.draw(mSprite);
}

}