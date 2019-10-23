#include "Deck.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

Deck::Deck() {       //constructor class for deck
    cout << "constructor called." << endl;
    cards = new Card[52];       //creating an array of Cards
    arraySize = 52;             //setting arraySize to 52
    cardsLeft = 0;              //setting cardsLeftValue
}


Deck::~Deck() {       //destructor
    cout << "Destructor called." << endl;
    delete [] cards;      //deletes array of cards
}


Deck :: Deck (const Deck& copyDeck ){         //copy constructor
    cout << "Copy Constructor called." << endl;
    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
    cards= new Card[arraySize];
    for(int i=0; i<arraySize;i++){
        cards[i]=copyDeck.cards[i];
    }
}

Deck &Deck::operator=(Deck assignment) {          //copy assignment operator
    cout<<"assignment operator called"<<endl;

    swap(cards, assignment.cards); //built-in swap
    arraySize = assignment.arraySize;
    cardsLeft = assignment.cardsLeft;
    return *this;
}


void Deck::shuffle(){           //shuffle function
    srand(time(0));       //use this so that there is a random deck each time
    for(int i = 0; i < pow(cardsLeft, 2); i++){           //how many times the deck will be shuffled
        swap(cards[rand() % 52],cards[rand() % 52]);        //swapping cards in the deck

    }
}

void Deck::populate() {       //populating the deck with cards
    for(int i = 0; i < 13; i++){      //for loop for the ranks
        for(int j = 0; j < 4; j++){     //for loop for the suits
           addCard(Card(i,j));         //adding cards with all the rank and suit values

        }
    }
}

Card Deck::removeCard() {          //remove cards from the deck
    return cards[--cardsLeft];
}

bool Deck::addCard(Card newCard) {        //add's cards to decks
    if(cardsLeft < arraySize){          //checks if there is room to add the card
        cards[cardsLeft++] = newCard;       //adds in the card at the correct position in the array
        return true;
    }
    return false;
}