#include "Card.h"
using namespace std;

Card::Card(){

}

Card::Card(int rank, int suit) {
    this-> rank = rank;
    this-> suit = suit;
}

bool Card::operator >(Card computer) {
    if(rank != computer.rank){
        return rank > computer.rank;
    }
    else{
        return suit >computer.suit;
    }

}
string Card::print() {
    return ranks[rank] + " of " + suits[suit];
}

