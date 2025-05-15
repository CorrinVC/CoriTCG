#include "UIImage.h"
#include <format>

namespace Cori {

sf::Texture gBlankTexture {};
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
    if(mHasCaption) {
        mCaption.draw(window);
    }
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
    setSize(); // TODO - Give UIElements Scale Factor Member Var
}

void UIImage::setPosition(float x, float y) {
    UIElement::setPosition(x, y);
    mSprite.setPosition({ x, y });
    if(mHasCaption) positionCaption();
}

void UIImage::move(float x, float y) {
    UIElement::move(x, y);
    mSprite.move({ x, y });
    if(mHasCaption) {
        mCaption.move(x, y);
        //mCaption.centerText();
    }
}

void UIImage::offsetFromOrigin(float xOffset, float yOffset) {
    UIElement::offsetFromOrigin(xOffset, yOffset);
    if(mHasCaption) {
        positionCaption();
        //mCaption.centerText();
    }
    mSprite.setPosition({ mOriginX + xOffset, mOriginY + yOffset });
}

void UIImage::setScale(float scaleFactor) {
    setScale(scaleFactor, scaleFactor);
}

void UIImage::setScale(float scaleX, float scaleY) {
    mSprite.setScale({ scaleX, scaleY });
    UIElement::setScale(scaleX, scaleY);
    if(mHasCaption) positionCaption();
}

void UIImage::setSize() {
    setSize(mImage.getSize().x, mImage.getSize().y);
}

void UIImage::setSize(float width, float height) {
    mWidth = width;
    mHeight = height;
    mRect.setSize({ mWidth, mHeight });
    if(mHasCaption) positionCaption();
}

void UIImage::setSubImage(int startX, int startY, int width, int height) {
    mSprite.setTextureRect({{ startX, startY }, { width, height }});
    setSize(mSprite.getTextureRect().size.x, mSprite.getTextureRect().size.y);
}

void UIImage::addCaption(UITextbox caption, float xOffset, float yOffset) {
    mCaption = caption;
    mCaptionXOffset = xOffset;
    mCaptionYOffset = yOffset;
    positionCaption();
    mCaption.centerText();

    //mCaption.setPosition(getX(), getY());
    //mCaption.setBackgroundColor(sf::Color(255,0,255));
    mHasCaption = true;
}

void UIImage::positionCaption() {
    float xOffset { 
        mCaptionXOffset >= 0 ? mCaptionXOffset
        : mRect.getSize().x + mCaptionXOffset 
    };
    float yOffset { 
        mCaptionYOffset >= 0 ? mCaptionYOffset
        : mRect.getSize().y + mCaptionYOffset
    };
    mCaption.setPosition(getX() + xOffset, getY() + yOffset);
}

sf::Texture UIImage::getImage() {
    return mImage;
}

sf::Sprite UIImage::getSprite() {
    return mSprite;
}

UITextbox& UIImage::getCaption() {
    assert(mHasCaption && "Image Has No Caption");
    return mCaption;
}

}