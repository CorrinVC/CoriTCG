#include "UIPanel.h"

namespace Cori {

UIPanel::UIPanel(float width, float height)
: UIPanel(0.0f, 0.0f, width, height)
{}

UIPanel::UIPanel(float x, float y, float width, float height)
: UIElement(x, y, width, height)
, mPanelView { sf::FloatRect({ x, y }, { width, height }) }
{ }

UIPanel::~UIPanel() {
    for(auto* element : mPanelElements)
        delete element;
}

void UIPanel::update() {
    for(auto* element : mPanelElements)
        element->update();
}

void UIPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    for(auto* element : mPanelElements)
        element->draw(window);

    window.setView(window.getDefaultView());
}

void UIPanel::addElement(UIElement* element) {
    mPanelElements.push_back(element);
}

sf::View& UIPanel::getView() {
    return mPanelView;
}

std::vector<UIElement*>& UIPanel::getElements() {
    return mPanelElements;
}

}