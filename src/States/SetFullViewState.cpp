#include "State.h"
#include "../Window.h"
#include "../UI/UIPanel.h"

namespace Cori { namespace SetFullView {

State gSetFullViewState {};

void initFullViewState() {
    UIElement* element = new UIElement(0.0f, 0.0f, 100.0f, 100.0f);
    element->setBackgroundColor(sf::Color::Green);

    UIElement* element2 = new UIElement(gWindowWidth - 250.0f, 0.0f, 250.0f, 250.0f);
    element2->setBackgroundColor(sf::Color::Red);

    UIElement* element3 = new UIElement(gWindowWidth / 2.0f - 150.0f, gWindowHeight - 500.0f, 300.0f, 500.0f);
    element3->setBackgroundColor(sf::Color::Cyan);

    UIPanel* panel = new UIPanel(gWindowWidth, gWindowHeight);
    panel->addElement(element);
    panel->addElement(element2);
    panel->addElement(element3);

    panel->getView().setScissor({{ 0.05f, 0.08f }, { 0.9f, 0.8f }});

    UIElement* element4 = new UIElement(200.0f, 200.0f);
    UIElement* element5 = new UIElement(gWindowWidth - 150.0f, 0.0f, 150.0f, 200.0f);
    gSetFullViewState.addUIElement(element4);
    gSetFullViewState.addUIElement(panel);
    gSetFullViewState.addUIElement(element5);


}


}}