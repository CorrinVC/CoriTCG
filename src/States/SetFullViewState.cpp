#include "State.h"
#include "../Window.h"
#include "../Cards/Card.h"
#include "../Cards/Expansions/Expansions.h"
#include "../UI/UIButton.h"
#include "../UI/UIImage.h"
#include "../UI/UIPanel.h"
#include <format>
#include <iostream>

namespace Cori { namespace SetFullView {

State gSetFullViewState {};

float currentScale { 2.0f };
int currentImgCount { 102 };
float regionBorder { 12.0f };
float cardGap { regionBorder - currentScale };
int cardsPerLine { int((gWindowWidth - regionBorder * 2) / (gCardWidth / currentScale + cardGap)) };

sf::Vector2f getIndexedPosition(int index) {
    return {
        ((gWindowWidth - (gCardWidth / currentScale + cardGap) * cardsPerLine + cardGap) / 2) + (index % cardsPerLine) * (gCardWidth / currentScale + cardGap),
        regionBorder + (index / cardsPerLine) * (gCardHeight / currentScale + cardGap) 
    };
}

void setImgPosition(int index, UIImage* image) {
    image->setPosition(getIndexedPosition(index).x, getIndexedPosition(index).y);
}

void updateImgTransformations(std::vector<UIElement*>& elements) {
    cardGap = std::max(1.0f, 12.0f - currentScale);
    cardsPerLine = int((gWindowWidth - regionBorder * 2) / (gCardWidth / currentScale + cardGap));

    for(int i = 0; i < currentImgCount; ++i) {
        UIImage* ptr { static_cast<UIImage*>(elements[i + 1]) };
        ptr->setScale(1.0f / currentScale);
        setImgPosition(i, ptr);
    }
    
}

float panelScaleFactor { 1.0f };

void updatePanelScale(UIPanel* panel) {
    panel->getView().setViewport({
        { (1.0f - panelScaleFactor) / 2.0f, (1.0f - panelScaleFactor) / 2.0f },
        { panelScaleFactor, panelScaleFactor }
    });
}

void initFullViewState() {
    UIPanel* panel = new UIPanel(gWindowWidth, gWindowHeight * 0.9f);

    UIElement* bkgd = new UIElement(gWindowWidth, gWindowHeight);
    bkgd->setBackgroundColor(sf::Color(255, 100, 100));
    panel->addElement(bkgd);

    //panel->getView().setScissor({{ 0.05f, 0.08f }, { 0.9f, 0.8f }});
    for(int i = 0; i < currentImgCount; ++i) {
        UIImage* image = new UIImage(getIndexedPosition(i).x, getIndexedPosition(i).y, Expansions::gExpansionList[0]->cards[i]->mTexture);
        image->setScale(1.0f / currentScale);
        panel->addElement(image);
    }

    panel->getView().setViewport({{ 0.0f, 0.05f }, { 1.0f, 0.95f }});

    UIButton* scaleDown = new UIButton(0.0f, 0.0f, 50.0f, 50.0f);
    scaleDown->getTextbox().setText("Down");
    scaleDown->createClickFunction(
        [=]() {
            currentScale += 1.0f;
            std::cout << currentScale << '\n';
            updateImgTransformations(panel->getElements());
        }
    );

    UIButton* scaleUp = new UIButton(gWindowWidth - 50.0f, 0.0f, 50.0f, 50.0f);
    scaleUp->getTextbox().setText("Up");
    scaleUp->createClickFunction(
        [=]() {
            if(currentScale > 1.0f) {
                currentScale -= 1.0f;
                updateImgTransformations(panel->getElements());
            }
            std::cout << currentScale << '\n';
        }
    );

    UIButton* downsize = new UIButton(0.0f, gWindowHeight - 50.0f, 50.0f, 50.0f);
    downsize->getTextbox().setText("-");
    downsize->createClickFunction(
        [=]() {
            if(panelScaleFactor > 0.1f) {
                panelScaleFactor -= 0.1f;
                updatePanelScale(panel);
            }
        }
    );

    UIButton* upsize = new UIButton(gWindowWidth - 50.0f, gWindowHeight - 50.0f, 50.0f, 50.0f);
    upsize->getTextbox().setText("+");
    upsize->createClickFunction(
        [=]() {
            if(panelScaleFactor < 1.0f) {
                panelScaleFactor += 0.1f;
                updatePanelScale(panel);
            }
        }
    );

    gSetFullViewState.addUIElement(panel);
    gSetFullViewState.addUIElement(scaleDown);
    gSetFullViewState.addUIElement(scaleUp);
    gSetFullViewState.addUIElement(upsize);
    gSetFullViewState.addUIElement(downsize);
}


}}