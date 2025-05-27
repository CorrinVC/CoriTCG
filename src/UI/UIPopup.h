#pragma once

#include "UIButton.h"
#include "UIPanel.h"

namespace Cori {

class UIPopup : public UIPanel {
    UITextbox mTitle;
    UIButton mConfirmButton;

public:
    UIPopup(float width, float height, sf::String title = "");
    UIPopup(float x, float y, float width, float height, sf::String title = "");

    void update();
    void draw(sf::RenderWindow& window);

    void alignConfirmButton(float x, float y);
    void setConfirmButtonSize(float width, float height);
    void setConfirmButtonText(sf::String text);
    void setConfirmFunction(std::function<void(void)> func);

    void alignTitle(float x, float y);
    void centerTitle();
    void setTitleSize(float width, float height);
    void setTitle(sf::String text);
};

}