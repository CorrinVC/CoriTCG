#include "UIImage.h"
#include <format>

namespace Cori {

constexpr std::string filePathPrefix { "res/" };
constexpr void checkFilePathPassed(const std::string_view texturePath) {
    assert(texturePath.substr(0, filePathPrefix.size()) != filePathPrefix && "texturePath prefixed with \'res/\'");
}

UIImage::UIImage(float x, float y, const std::string_view texturePath)
: UIElement(x, y, 0.0f, 0.0f)
, mImage { std::format("res/{}", texturePath) }
, mSprite { mImage }
{
    checkFilePathPassed(texturePath);
    /*setSize({ 
        static_cast<float>(mImage.getSize().x), 
        static_cast<float>(mImage.getSize().y)
    });*/
    mSprite.setPosition({ x, y });
}

void UIImage::draw(sf::RenderWindow& window) {
    window.draw(mSprite);
}

void UIImage::changeTexture(const std::string_view texturePath) {
    checkFilePathPassed(texturePath);
    assert(mImage.loadFromFile(std::format("res/{}", texturePath)));
    mSprite.setTexture(mImage, true);
}

}