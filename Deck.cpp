#include "Deck.h"
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

Deck::Deck() {
    cout << "constructor called." << endl;
    cards = new Card[52];
    arraySize = 52;
    cardsLeft = 0;
}


Deck::~Deck() {
    cout << "Destructor called." << endl;
    delete [] cards; //add something to delete
}


Deck :: Deck (const Deck& copyDeck ){
    cout << "Copy Constructor called." << endl;
    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
    cards= new Card[arraySize];
    for(int i=0; i<arraySize;i++){
        cards[i]=copyDeck.cards[i];
    }
}

Deck &Deck::operator=(Deck assignment) {
    cout<<"assignment operator called"<<endl;

    swap(cards, assignment.cards); //built-in swap
    arraySize = assignment.arraySize;
    cardsLeft = assignment.cardsLeft;
    return *this;
}


void Deck::shuffle(){
    srand(time(0));
    for(int i = 0; i < pow(cardsLeft, 2); i++){
        swap(cards[rand() % 52],cards[rand() % 52]);

    }
}

void Deck::populate() {
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
           addCard(Card(i,j));

        }
    }
}

Card Deck::removeCard() {
    return cards[--cardsLeft];
}

bool Deck::addCard(Card newCard) {
    if(cardsLeft < arraySize){
        cards[cardsLeft++] = newCard;
        return true;
    }
    return false;
}