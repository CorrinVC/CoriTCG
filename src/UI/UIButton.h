#pragma once

#include "UIElement.h"
#include "UITextbox.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Cori {

class UIButton : public UIElement {
private:
    // change to uitextbox
    UITextbox mTextbox;

public:
    UIButton(float width, float height);
    UIButton(float x, float y, float width, float height);

    void update();
    void draw(sf::RenderWindow& window) override;

    void offsetFromOrigin(float xOffset, float yOffset) override;
    void setSize(const sf::Vector2f& size) override;

    // Prefer Wrapper Functions
    UITextbox& getTextbox();

    // Wrapper Functions
    void setText(const sf::String& text);
    void centerButtonText();

    void setTextColor(sf::Color color);
    void setTextHoverColor(sf::Color color);
    void setTextPressedColor(sf::Color color);
};

extern std::function<void()> gOnBackClick;

class BackButton : public UIButton {
private:
    bool mSaysBack { true };
    void init();
public:
    BackButton(float width, float height, bool saysBack = true);
    BackButton(float x, float y, float width, float height, bool saysBack = true);
};

}