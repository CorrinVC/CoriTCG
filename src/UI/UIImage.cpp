#include "UIImage.h"
#include <format>

namespace Cori {

sf::Texture gCardBackTexture { "res/card-back.png" };

constexpr std::string filePathPrefix { "res/" };

// File Path Check Helper
constexpr bool printTexturePath(const std::string_view texturePath) {
    std::cout << "Texture Path: '" << texturePath << "' prefixed with 'res/'" << std::endl;
    return false; 
}

// Check File Path Does not Begin with FilePathPrefix ('res/')
constexpr void checkFilePathPassed(const std::string_view texturePath) {
    assert((std::string(texturePath).compare(0, 4, filePathPrefix)) != 0 || printTexturePath(texturePath));
}

UIImage::UIImage(float x, float y, const std::string_view texturePath)
: UIElement(x, y, 0.0f, 0.0f)
, mImage { std::format("res/{}", texturePath) }
, mSprite { mImage }
{
    checkFilePathPassed(texturePath);
    
    setSize(); // Setting Bounding Box Size After mImage Initialization
    mSprite.setPosition({ x, y });
}

UIImage::UIImage(float x, float y, sf::Texture texture) 
: UIElement(x, y, 0.0f, 0.0f)
, mImage { texture }
, mSprite { mImage }
{
    setSize(); // Setting Bounding Box Size After mImage Initialization
    mSprite.setPosition({ x, y });
}

void UIImage::draw(sf::RenderWindow& window) {
    window.draw(mSprite);
}

void UIImage::changeTexture(const std::string_view texturePath) {
    checkFilePathPassed(texturePath);
    assert(mImage.loadFromFile(std::format("res/{}", texturePath)));

    mSprite.setTexture(mImage, true);
    setSize();
}

void UIImage::changeTexture(sf::Texture texture) {
    mImage.swap(texture);

    mSprite.setTexture(mImage, true);
    setSize();
}

void UIImage::setPosition(float x, float y) {
    UIElement::setPosition(x, y);
    mSprite.setPosition({ x, y });
}

void UIImage::move(float x, float y) {
    UIElement::move(x, y);
    mSprite.move({ x, y });
}

void UIImage::setScale(float scaleFactor) {
    setScale(scaleFactor, scaleFactor);
}

void UIImage::setScale(float scaleX, float scaleY) {
    mSprite.setScale({ scaleX, scaleY });
    UIElement::setSize({ mImage.getSize().x * scaleX, mImage.getSize().y * scaleY});
}

void UIImage::setSize() {
    mWidth = mImage.getSize().x;
    mHeight = mImage.getSize().y;
    mRect.setSize({ mWidth, mHeight });
}

}