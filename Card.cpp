#include <iostream>
#include "Card.h"
using namespace std;

Card::Card(){

}

Card::Card(string rank, string suits) {
    this-> rank = rank;
    this-> suits = suits;
}

bool Card::operator<(Card *computer) {
    if(rank != computer->rank){   
        return rank < computer->rank;
    }
    else{
        return suits < computer->suits;
    }

}
void Card::print() {

}

