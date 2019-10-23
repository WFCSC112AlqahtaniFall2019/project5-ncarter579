#include <iostream>
#include <string>

#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;

    Deck *cardPile = new Deck();
    Deck *discardPile = new Deck();

    cardPile->populate();
    cardPile->shuffle();

    play = true;
    while(play) {
        // assign values to computer and user


        Card user = (cardPile->removeCard());
        Card computer = cardPile->removeCard();

        //int randomRank = rand() % 13;
        //int randomSuit = rand() % 4;
        //Card *user = new Card(randomRank, randomSuit);

        //randomRank = rand() % 13;
        //randomSuit = rand() % 4;
        //Card *computer = new Card(randomRank, randomSuit);

        // get user's bet
        cout << "Computer's card is " << computer.print() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your card is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if((user>computer && guessedHigher) || ( computer > user && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((computer > user  && guessedHigher) || (user > computer && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << user.print() << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing

                discardPile->addCard(user);
                discardPile->addCard(computer);

                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;


      return 0;
}