#include "UIPopup.h"
#include "../DeletionProtection.h"
#include "../Input/MouseManager.h"

namespace Cori {

UIPopup::UIPopup(float width, float height, sf::String title)
: UIPopup(0.0f, 0.0f, width, height, title)
{}

UIPopup::UIPopup(float x, float y, float width, float height, sf::String title)
: UIPanel(x, y, width, height)
, mTitle { 
    150.0f <= width ? 150.0f : width, 
    50.0f <= height ? 50.0f : height, 
    title }
, mConfirmButton { 
    60.0f <= width ? 60.0f : width, 
    30.0f<= height ? 30.0f : height }
{
    setViewport(x, y, width, height);

    mConfirmButton.setText("OK");
    mConfirmButton.centerButtonText();
    mConfirmButton.createClickFunction([this]() {
        hide();
    });
}

void UIPopup::update() {
    gMouseManager.setInView(mPanelView);

    mConfirmButton.update();
    mTitle.update();
    updateElements();
    UIElement::update();

    gMouseManager.setInView(false);
}

void UIPopup::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    drawElements(window);
    mConfirmButton.draw(window);
    mTitle.draw(window);

    window.setView(window.getDefaultView());
}

void UIPopup::alignConfirmButton(float x, float y) {
    mConfirmButton.setPosition(x, y);
    mConfirmButton.centerButtonText();
}

void UIPopup::setConfirmButtonSize(float width, float height) {
    mConfirmButton.setSize({ width, height });
    mConfirmButton.centerButtonText();
}

void UIPopup::setConfirmButtonText(sf::String text) {
    mConfirmButton.setText(text);
    mConfirmButton.centerButtonText();
}

void UIPopup::setConfirmFunction(std::function<void(void)> func) {
    mConfirmButton.createClickFunction([=, this]() {
        func();
        hide();
    });
}

void UIPopup::alignTitle(float x, float y) {
    mTitle.setPosition(x, y);
    if(mTitle.isCentered()) mTitle.centerText();
}

void UIPopup::centerTitle() {
    mTitle.centerText();
}

void UIPopup::setTitleSize(float width, float height) {
    mTitle.setSize({ width, height });
    if(mTitle.isCentered()) mTitle.centerText();
}

void UIPopup::setTitle(sf::String text) {
    mTitle.setText(text);
    if(mTitle.isCentered()) mTitle.centerText();
}

UITextbox& UIPopup::getTitleBox() {
    return mTitle;
}

UIButton& UIPopup::getConfirmButton() {
    return mConfirmButton;
}

}