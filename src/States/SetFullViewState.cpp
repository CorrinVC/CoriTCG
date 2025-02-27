#include "State.h"
#include "../Window.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIButton.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollBar.h"
#include "../UI/UIScrollPanel.h"
#include <format>

namespace Cori { namespace SetFullView {

State gSetFullViewState {};

float currentScale { 2.0f }; // Card Image Scale Factor (Represented as 1/x)
int currentImgCount { 102 }; // Temporary - Replace with Expansion var & Expansion Card Count var
float regionBorder { 12.0f }; // CHANGE? Panel Inner Padding, in Pixels
float cardGap { regionBorder - currentScale }; // Padding Between Cards, in Pixels

// Amount of Cards that fit in a row, given Scale, Gap, and Border
int cardsPerLine { int((gWindowWidth - regionBorder * 2) / (gCardWidth / currentScale + cardGap)) };

// Returns Position of Card Relative to its Indexed Location in grid
sf::Vector2f getIndexedPosition(int index) {
    return {
        ((gWindowWidth - (gCardWidth / currentScale + cardGap) * cardsPerLine + cardGap) / 2) + (index % cardsPerLine) * (gCardWidth / currentScale + cardGap),
        regionBorder + (index / cardsPerLine) * (gCardHeight / currentScale + cardGap) 
    };
}

void setImgPosition(int index, UIImage* image) {
    image->setPosition(getIndexedPosition(index).x, getIndexedPosition(index).y);
}

// Update Card Gap & Cards Per Line when Scaling
// Cycle Through Card UIImages, Adjust Scale & Position
void updateImgTransformations(std::vector<UIElement*>& elements) {
    cardGap = std::max(1.0f, 12.0f - currentScale);
    cardsPerLine = int((gWindowWidth - regionBorder * 2) / (gCardWidth / currentScale + cardGap));

    for(int i = 0; i < currentImgCount; ++i) {
        UIImage* ptr { static_cast<UIImage*>(elements[i]) };
        ptr->setScale(1.0f / currentScale);
        setImgPosition(i, ptr);
    }
    
}

float panelScaleFactor { 1.0f }; // Viewport size factor (Relative to Screen Size)

// Temporary? Used for experimenting with Viewports
void updatePanelScale(UIPanel* panel) {
    panel->getView().setViewport({
        { (1.0f - panelScaleFactor) / 2.0f, (1.0f - panelScaleFactor) / 2.0f },
        { panelScaleFactor, panelScaleFactor }
    });
}

void initFullViewState() {
    // Main Panel on which to Display main Card UIImages
    UIScrollPanel* panel = new UIScrollPanel(gWindowWidth, gWindowHeight * 0.9f, UIScrollBar(20.0f, 50.0f));
    panel->setBackgroundColor(sf::Color(255, 100, 100));

    // Initialize Amount of UIImages equal to Current Expansion Card Count
    // Rework? Needs Functionality for Changing Amount of Cards to Display
    for(int i = 0; i < currentImgCount; ++i) {
        UIImage* image = new UIImage(getIndexedPosition(i).x, getIndexedPosition(i).y, Expansions::gExpansionList[0]->cards[i]->mTexture);
        image->setScale(1.0f / currentScale);
        panel->addElement(image);
    }

    // Sets Panel Size to 95% of Screen Height, Aligned to Bottom of Screen
    panel->getView().setViewport({{ 0.0f, 0.05f }, { 1.0f, 0.95f }});

    // Temporary? Scales UIElements Down
    UIButton* scaleDown = new UIButton(0.0f, 0.0f, 50.0f, 50.0f);
    scaleDown->getTextbox().setText("Down");
    scaleDown->createClickFunction(
        [=]() {
            currentScale += 1.0f;
            updateImgTransformations(panel->getElements());
        }
    );

    // Temporary? Scales UIElements Up
    UIButton* scaleUp = new UIButton(gWindowWidth - 50.0f, 0.0f, 50.0f, 50.0f);
    scaleUp->getTextbox().setText("Up");
    scaleUp->createClickFunction(
        [=]() {
            if(currentScale > 1.0f) {
                currentScale -= 1.0f;
                updateImgTransformations(panel->getElements());
            }
        }
    );

    // Temporary Button in Place of Scroll Functionality
    UIButton* scrollDown = new UIButton(0.0f, gWindowHeight - 100.0f, 50.0f, 50.0f);
    scrollDown->getTextbox().setText("-");
    scrollDown->createClickFunction(
        [=]() {
            panel->offsetElements(0.0f, 1.0f);
        }
    );

    // Temporary Button in Place of Scroll Functionality
    UIButton* scrollUp = new UIButton(gWindowWidth - 50.0f, gWindowHeight - 100.0f, 50.0f, 50.0f);
    scrollUp->getTextbox().setText("+");
    scrollUp->createClickFunction(
        [=]() {
            panel->offsetElements(0.0f, -1.0f);
        }
    );

    gSetFullViewState.addUIElement(panel);
    gSetFullViewState.addUIElement(scaleDown);
    gSetFullViewState.addUIElement(scaleUp);
    gSetFullViewState.addUIElement(scrollUp);
    gSetFullViewState.addUIElement(scrollDown);
}


}}