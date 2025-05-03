#include "DecklistLayout.h"
#include "UIImage.h"

namespace Cori {

DecklistLayout* gDecklistLayout = new DecklistLayout();

void initDecklistLayout() {
    gDecklistLayout->setBackgroundColor(sf::Color::Green);
    gDecklistLayout->setInnerPadding(13.0f);
}

DecklistLayout::DecklistLayout()
: DecklistLayout(gWindowWidth, gWindowHeight)
{}

DecklistLayout::DecklistLayout(float width, float height)
: UIGridLayout(10.0f, 8.0f, width, height)
{}

void DecklistLayout::generateImage(QuantityCard& card) {
    UIImage* img = new UIImage(0.0f, 0.0f, card.card->mTexture);

    img->addCaption({ 50.0f, 25.0f, std::format("{}", card.quantity) }, 
        0.0f, -25.0f);
    img->getCaption().setBackgroundColor(sf::Color::Black);

    addElement(img);
}

void DecklistLayout::incrementImage(QuantityCard& card) {
    UIImage* img { static_cast<UIImage*>(
        getElements()[mCurrentDeck.findCardIndex(card.card)]
    )};

    img->getCaption().setText(std::format("{}", card.quantity));
}

void DecklistLayout::changeImage(QuantityCard& card, int imgIndex) {
    UIImage* img { static_cast<UIImage*>(getElements()[imgIndex]) };

    img->changeTexture(card.card->mTexture);
    img->setScale(1.0f / mScaleFactor);
    img->getCaption().setText(std::format("{}", card.quantity));
    //img->getCaption().setPosition()
}

void DecklistLayout::sortDecklist() {
    int cardIndex { 0 };
    for(QuantityCard card : mCurrentDeck.getSortedList(mSortMethod)) {
        changeImage(card, cardIndex);
        ++cardIndex;
    }
}

void DecklistLayout::updateDecklist() {
    clearElements();
    for(QuantityCard card : mCurrentDeck.getSortedList(mSortMethod))
        addToDeck(card);
}

void DecklistLayout::addToDeck(QuantityCard& card) {
    // Player Has No More of Card to Add
    if(mCurrentDeck.getCountOfCard(card.card) >= card.quantity) return;
    
    // Adding Card is Valid
    if(mCurrentDeck.addCard(card.card)) {
        if(mCurrentDeck.getCountOfCard(card.card) > 1)
            incrementImage(card);
        else
            generateImage(card);
    }

    sortDecklist();
}

void DecklistLayout::changeSortMethod(SortMethod method) {
    mSortMethod = method;
    sortDecklist();
}

void DecklistLayout::printDeck() {
    for(QuantityCard card : mCurrentDeck.getCards()) {
        std::cout << card.quantity << "x ";
        card.print();
    }
}

void DecklistLayout::reset() {
    mCurrentDeck = {};
    clearElements();
}

void DecklistLayout::setDeck(DeckList deck) {
    mCurrentDeck = deck;
    updateDecklist();
}

DeckList DecklistLayout::getCurrentDeck() {
    return mCurrentDeck;
}

int DecklistLayout::findCardIndex(QuantityCard& card) {
    return mCurrentDeck.findSortedIndex(card.card, mSortMethod);
}

}