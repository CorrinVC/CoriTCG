#include "UIPanel.h"
#include "CollectionLayout.h"
#include "DecklistLayout.h"
#include "../DeletionProtection.h"
#include "../Input/MouseManager.h"

namespace Cori {

UIPanel::UIPanel(float width, float height)
: UIPanel(0.0f, 0.0f, width, height)
{}

UIPanel::UIPanel(float x, float y, float width, float height)
: UIElement(x, y, width, height)
, mPanelView { sf::FloatRect({ x, y }, { width, height }) }
{ }

UIPanel::~UIPanel() {
    for(auto* element : mPanelElements) {
        if(deletionProtectionContains(element)) continue;
        delete element;
        element = NULL;
    }
}

void UIPanel::updateElements() {
    for (std::vector<UIElement*>::reverse_iterator elements = mPanelElements.rbegin();
            elements != mPanelElements.rend(); ++elements)
        (*elements)->update();
}

void UIPanel::update() {
    gMouseManager.setInView(mPanelView);

    updateElements();
    UIElement::update();

    gMouseManager.setInView(false);
}

// Helper Function for Subclasses Drawing Elements Besides mPanelElements Members
void UIPanel::drawElements(sf::RenderWindow& window) {
    window.draw(mRect);

    for(auto* element : mPanelElements) {
        if(inBounds({ element->getX(), element->getY() }) // Checks if Element Top Left is inBounds
            // Checks if Element Bottom Right is inBounds
            || inBounds({ element->getX() + element->getWidth() - 1, 
                          element->getY() + element->getHeight() - 1 })) {
            element->draw(window);
        }
    }

}

void UIPanel::draw(sf::RenderWindow& window) {
    window.setView(mPanelView);

    drawElements(window);

    window.setView(window.getDefaultView());
}

void UIPanel::addElement(UIElement* element) {
    mPanelElements.push_back(element);
}

void UIPanel::setViewport(float startX, float startY, float width, float height) {
    if(startX > 1.0f) startX /= gWindowWidth;
    if(startY > 1.0f) startY /= gWindowHeight;
    if(width > 1.0f) width /= gWindowWidth;
    if(height > 1.0f) height /= gWindowHeight;

    mPanelView.setViewport({{ startX, startY }, { width, height }});
}

sf::View& UIPanel::getView() {
    return mPanelView;
}

std::vector<UIElement*>& UIPanel::getElements() {
    return mPanelElements;
}

}