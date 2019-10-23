#include "Deck.h"
#include <iostream>
#include <math.h>

using namespace std;


Deck::~Deck() {
    cout << "Destructor called." << endl;
    delete [] cards; //add something to delete
}


Deck :: Deck (const Deck& copyDeck ){
    cout << "Copy Constructor called." << endl;
    *cards = *(copyDeck.cards);
    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
}

Deck &Deck::operator=(Deck assignment) {
    cout<<"assignment operator called"<<endl;

    swap(cards, assignment.cards); //built-in swap
    arraySize = assignment.arraySize;
    cardsLeft = assignment.cardsLeft;
    return *this;
}


void Deck::shuffle(){
    Card temp;
    for(int i = 0; i < pow(cardsLeft, 2); i++){
        swap(cards[rand() % 52],cards[rand() % 52]);

    }
}

void Deck::populate() {
    for(int i = 0; i < ranks->length(); i++){
        for(int j = 0; j < suits->length(); j++){
           addCard(Card(i,j));
        }
    }
}

Card Deck::removeCard() {
    return cards[cardsLeft--];
}

bool Deck::addCard(Card newCard) {
    if(cardsLeft < arraySize){
        cards[++cardsLeft] = newCard;
    }
}