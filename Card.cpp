#include "Card.h"
using namespace std;

Card::Card(){            //default constructor for class Card

}

Card::Card(int rank, int suit) {        //constructor for class Card
    this-> rank = rank;
    this-> suit = suit;
}

bool Card::operator >(Card computer) {     //overload operator for the > symbol
    if(rank != computer.rank){
        return rank > computer.rank;
    }
    else{
        return suit >computer.suit;
    }

}
string Card::print() {                   //prints the card's rank and suit
    return ranks[rank] + " of " + suits[suit];
}

