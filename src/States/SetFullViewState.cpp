#include "State.h"
#include "../Window.h"
#include "../Cards/Expansions/Expansions.h"

#include "../UI/UIElement.h"
#include "../UI/UIButton.h"
#include "../UI/UIDropdown.h"
#include "../UI/UIImage.h"
#include "../UI/UIScrollBar.h"
#include "../UI/UIScrollPanel.h"
#include "../UI/UITextbox.h"
#include <format>

namespace Cori { namespace SetFullView {

State gSetFullViewState {};

// UI Elements
UIDropdown* expansionDropdown;
UIScrollPanel* panel;

UIButton* scaleDown;
UIButton* scaleUp;
UIButton* scrollDown;
UIButton* scrollUp;

// Layout Variables

float currentScale { 2.0f }; // Card Image Scale Factor (Represented as 1/x)
int currentImgCount { 102 }; // Temporary - Replace with Expansion var & Expansion Card Count var
const float regionBorder { 12.0f }; // CHANGE? Panel Inner Padding, in Pixels
float cardGap { regionBorder - currentScale }; // Padding Between Cards, in Pixels

// Amount of Cards that fit in a row, given Scale, Gap, and Border
int cardsPerLine { int((gWindowWidth - regionBorder * 2) / (gCardWidth / currentScale + cardGap)) };

// Current Set Vars
Expansion* currentExpansion { Expansions::gExpansionList[ExpansionID::BaseSet] };

// Returns Position of Card Relative to its Indexed Location in grid
sf::Vector2f getIndexedPosition(int index) {
    return {
        ((gWindowWidth - (gCardWidth / currentScale + cardGap) * cardsPerLine + cardGap) / 2) 
        + (index % cardsPerLine) * (gCardWidth / currentScale + cardGap),
        regionBorder + (index / cardsPerLine) * (gCardHeight / currentScale + cardGap) 
    };
}

void generateImage(int index) {
    UIImage* image = new UIImage(getIndexedPosition(index).x, getIndexedPosition(index).y, 
        currentExpansion->cards[index]->mTexture);

    image->createClickFunction(
        [=]() {
            SetViewer::setSelectedCard(index + 1, currentExpansion->expansionID);
            gSetState(SetViewer::gSetViewerState);
            //std::cout << image->getX() << ',' << image->getY() << ',' << image->getWidth() << ',' << image->getHeight() << std::endl;
        }
    );

    image->setScale(1.0f / currentScale);
    panel->addElement(image);
}

void setImgPosition(int index, UIImage* image) {
    image->setPosition(getIndexedPosition(index).x, getIndexedPosition(index).y);
}

// Update Card Gap & Cards Per Line when Scaling
// Cycle Through Card UIImages, Adjust Scale & Position
void adjustScale() {
    cardGap = std::max(1.0f, 12.0f - currentScale);
    cardsPerLine = int((gWindowWidth - regionBorder * 2) / (gCardWidth / currentScale + cardGap));
}

void updateImgTransformation(int imgIndex, UIImage* img) {
    img->setScale(1.0f / currentScale);
    setImgPosition(imgIndex, img);
}

void updateImgTransformations(std::vector<UIElement*>& elements) {
    for(int i = 0; i < currentImgCount; ++i) {
        updateImgTransformation(i, static_cast<UIImage*>(elements[i]));
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

void reduceElements(int elementsNeeded) {
    for(int i = static_cast<int>(panel->getElements().size()) - 1; i >= elementsNeeded; --i) {
        delete panel->getElements()[i];
        panel->getElements().pop_back();
    }
}

void updateExpansion() {
    int i { 0 };

    for(UIElement* img : panel->getElements()) {
        if(dynamic_cast<UIImage*>(img)) {
            UIImage* ptr = static_cast<UIImage*>(img);
            if(i >= currentExpansion->cardCount())
                break;
            ptr->changeTexture(sf::Texture(currentExpansion->cards[i]->mTexture));
            updateImgTransformation(i, ptr);
            ++i;
        }
    }   
    std::cout << i << std::endl;

    // Reduce Elements
    if(i < static_cast<int>(panel->getElements().size())) {
        reduceElements(i);
    } else if(currentExpansion->cardCount() > i) {
        for(; i < currentExpansion->cardCount(); ++i) {
            generateImage(i);
        }
    }

    panel->calculateContentHeight();
}

void initFullViewState() {
    expansionDropdown = new UIDropdown(gWindowWidth / 2.0f - 150.0f, 10.0f, 300.0f, 40.0f, "Select Expansion",
        Expansions::gExpansionNames());
    expansionDropdown->createClickFunction(
        []() {
            if(expansionDropdown->getSelectedText() != gDefaultString) {
                currentExpansion = Expansions::gExpansionList[expansionDropdown->getSelectedIndex()];
                updateExpansion();
            }
        }
    );

    // Main Panel on which to Display main Card UIImages
    panel = new UIScrollPanel(gWindowWidth, gWindowHeight * 0.9f, 20.0f, 50.0f);
    panel->setBackgroundColor(sf::Color(255, 100, 100));
    panel->setInnerBorder(regionBorder);

    // Initialize Amount of UIImages equal to Current Expansion Card Count
    // Rework? Needs Functionality for Changing Amount of Cards to Display
    for(int i = 0; i < currentImgCount; ++i) {
        generateImage(i);
    }

    // Sets Panel Size to 95% of Screen Height, Aligned to Bottom of Screen
    panel->getView().setViewport({{ 0.0f, 0.05f }, { 1.0f, 0.95f }});

    // Temporary? Scales UIElements Down
    scaleDown = new UIButton(0.0f, 0.0f, 50.0f, 50.0f);
    scaleDown->setText("Down");
    scaleDown->createClickFunction(
        [=]() {
            currentScale += 1.0f;
            adjustScale();
            updateImgTransformations(panel->getElements());
            panel->calculateContentHeight();
        }
    );

    // Temporary? Scales UIElements Up
    scaleUp = new UIButton(gWindowWidth - 50.0f, 0.0f, 50.0f, 50.0f);
    scaleUp->setText("Up");
    scaleUp->createClickFunction(
        [=]() {
            if(currentScale > 1.0f) {
                currentScale -= 1.0f;
                adjustScale();
                updateImgTransformations(panel->getElements());
                panel->calculateContentHeight();
            }
        }
    );

    // Temporary Button in Place of Scroll Functionality
    scrollDown = new UIButton(0.0f, gWindowHeight - 100.0f, 50.0f, 50.0f);
    scrollDown->setText("-");
    scrollDown->createClickFunction(
        [=]() {
            panel->offsetElements(0.0f, 1.0f);
        }
    );

    // Temporary Button in Place of Scroll Functionality
    scrollUp = new UIButton(gWindowWidth - 50.0f, gWindowHeight - 100.0f, 50.0f, 50.0f);
    scrollUp->setText("+");
    scrollUp->createClickFunction(
        [=]() {
            panel->offsetElements(0.0f, -1.0f);
        }
    );

    
    gSetFullViewState.addUIElement(panel);
    gSetFullViewState.addUIElement(expansionDropdown);
    gSetFullViewState.addUIElement(scaleDown);
    gSetFullViewState.addUIElement(scaleUp);
    //gSetFullViewState.addUIElement(scrollUp);
    //gSetFullViewState.addUIElement(scrollDown);
}


}}