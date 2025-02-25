#include "UIPanel.h"

namespace Cori {

UIPanel::UIPanel(float width, float height)
: UIPanel(0.0f, 0.0f, width, height)
{}

UIPanel::UIPanel(float x, float y, float width, float height)
: UIElement(x, y, width, height)
, mPanelView { sf::FloatRect({ x, y }, { width, height }) }
{ }

void UIPanel::update() {
    for(UIElement* element : mPanelElements)
        element->update();
}

void UIPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    for(UIElement* element : mPanelElements)
        element->draw(window);

    window.setView(window.getDefaultView());
}

void UIPanel::addElement(UIElement* element) {
    mPanelElements.push_back(element);
}

sf::View& UIPanel::getView() {
    return mPanelView;
}

}