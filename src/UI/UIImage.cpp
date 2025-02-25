#include "UIImage.h"
#include <format>
#include <iostream>

namespace Cori {

constexpr std::string filePathPrefix { "res/" };

constexpr bool printTexturePath(const std::string_view texturePath) {
    std::cout << "Texture Path: '" << texturePath << "' prefixed with 'res/'" << std::endl;
    return false; 
}

constexpr void checkFilePathPassed(const std::string_view texturePath) {
    assert((std::string(texturePath).compare(0, 4, filePathPrefix)) != 0 || printTexturePath(texturePath));
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

UIImage::UIImage(float x, float y, sf::Texture texture) 
: UIElement(x, y, 0.0f, 0.0f)
, mImage { texture }
, mSprite { mImage }
{
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

void UIImage::changeTexture(sf::Texture texture) {
    mImage.swap(texture);
    mSprite.setTexture(mImage, true);
}

void UIImage::setPosition(float x, float y) {
    mSprite.setPosition({ x, y });
}

void UIImage::setScale(float scaleFactor) {
    setScale(scaleFactor, scaleFactor);
}

void UIImage::setScale(float scaleX, float scaleY) {
    mSprite.setScale({ scaleX, scaleY });
}

}