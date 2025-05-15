#include "State.h"
#include "../Window.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIElement.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIGridLayout.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollBar.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UITextbox.h"

namespace Cori { namespace SetFullView {

State gSetFullViewState {};

// UI Elements

UIDropdown* expansionDropdown;
UIGridLayout* gridLayout;
UIScrollPanel* panel;

UIButton* backButton;
UIButton* scaleDown;
UIButton* scaleUp;

// Reference Variables

float currentScale { 2.0f };
Expansion* currentExpansion{ Expansions::gExpansionList[0] };

void generateImage(int index) {
    UIImage* image = new UIImage(0.0f, 0.0f,
        currentExpansion->cards[index]->mTexture);
    
    image->createClickFunction([=]() {
        SetViewer::setSelectedCard(index + 1, currentExpansion->expansionID);
        gSetState(SetViewer::gSetViewerState);
    });
    gridLayout->addElement(image);
}

void updateExpansion() {
    gridLayout->clearElements();
    for(int i { 0 }; i < currentExpansion->cardCount(); ++i) 
        generateImage(i);
    panel->calculateContentHeight();

    if(gridLayout->getWidth() != panel->getWidthMinusScrollbar())
        gridLayout->setSize({ panel->getWidthMinusScrollbar(), gridLayout->getHeight() });
}

void initExpansionDropdown() {
    expansionDropdown = new UIDropdown(gWindowWidth / 2.0f - 150.0f, 10.0f, 300.0f, 40.0f, "Select Expansion",
        Expansions::gExpansionNames());
    expansionDropdown->createClickFunction([=]() {
        if(expansionDropdown->getSelectedIndex() >= 0) {
            currentExpansion = Expansions::gExpansionList[expansionDropdown->getSelectedIndex()];
            updateExpansion();
        }
    });
}

void initSetViewPanel() {
    panel = new UIScrollPanel(gWindowWidth, gWindowHeight * 0.9f);
    panel->setBackgroundColor(sf::Color(255, 100, 100));
    panel->setViewport(0.0f, 0.05f, 1.0f, 0.95f);
}

void initGridLayout() {
    gridLayout = new UIGridLayout(10.0f, 10.0f, panel->getWidthMinusScrollbar());
    gridLayout->setScale(currentScale);
    gridLayout->setBackgroundColor(sf::Color(200, 200, 255));
    
    panel->addElement(gridLayout);
    updateExpansion();
}

void initScaleUpButton() {
    scaleUp = new UIButton(gWindowWidth - 50.0f, 0.0f, 50.0f, 50.0f);
    scaleUp->setText("+");
    scaleUp->centerButtonText();
    
    scaleUp->createClickFunction([=]() {
        if(currentScale > 1.0f) {
            currentScale -= 1.0f;
            gridLayout->setScale(currentScale);
            panel->calculateContentHeight();
        }
    });
}

void initScaleDownButton() {
    scaleDown = new UIButton(50.0f, 50.0f);
    scaleDown->setPositionRelativeTo(*scaleUp, -50.0f, 0.0f);
    scaleDown->setText("-");
    scaleDown->centerButtonText();
    
    scaleDown->createClickFunction([=]() {
        currentScale += 1.0f;
        gridLayout->setScale(currentScale);
        panel->calculateContentHeight();
    });
}

void addElements() {
    gSetFullViewState.addUIElement(panel);
    gSetFullViewState.addUIElement(expansionDropdown);

    gSetFullViewState.addUIElement(backButton);
    gSetFullViewState.addUIElement(scaleDown);
    gSetFullViewState.addUIElement(scaleUp);
}

void initFullViewState() {
    gSetFullViewState.setOffSwitch([=]() {
        panel->resetScrollbar();
    });

    initExpansionDropdown();
    initSetViewPanel();
    initGridLayout();

    backButton = new BackButton(10.0f, 0.0f, 60.0f, 50.0f);
    initScaleUpButton();
    initScaleDownButton();

    addElements();
}

}}