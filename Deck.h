#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
    Deck ( const Deck & lis );
    ~ Deck ();
    Deck& operator= (Deck assignment );
    void shuffle();
    void populate();
    Card removeCard();
    bool addCard(Card newCard);

private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
