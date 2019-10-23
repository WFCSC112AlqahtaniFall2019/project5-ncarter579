#include <iostream>
#include <string>

#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;   //declaring variables used throughout the program
    string response;
    int nWin = 0, nLoss = 0, nTie = 0;
    int cardCount = 0;               //variable used to end the game if all the cards are used

    Deck cardPile;  //creating the original deck of cards
    Deck discardPile; //creating the discard deck

    cardPile.populate();        //populating cardPile with all the cards in the deck
    cardPile.shuffle();         //shuffling the deck so that the cards come out in a random order

    play = true;
    while(play) {
        // assign values to computer and user
        Card user = (cardPile.removeCard());      //drawing the user's card from cardPile
        Card computer = cardPile.removeCard();     //drawing the computer's card from cardPile
        cardCount = cardCount + 2;       //iterating cartCount to keep track of the number of cards drawn

        // get user's bet
        cout << "Computer's card is " << computer.print() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your card is higher or lower? (H/L)" << endl;
            cin >> response;          //getting the user's guess
            if (toupper(response.at(0)) == 'H') {      //pulling the correct value into guessesHigher and invalid based on the guess
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
        if((user>computer && guessedHigher) || ( computer > user && !guessedHigher)) {          //checks to see if your guess of higher or lower is correct
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((computer > user  && guessedHigher) || (user > computer && !guessedHigher)) {     //checks to see if your guess of higher or lower is incorrect
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {       //if neither of those are true it registers as a tie
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << user.print() << endl;   //prints out your card after the guess

        if(cardCount == 52){           //checks to see if the max cards are reached and if so prints all this and ends the game
            cout << "Ran out of cards" << endl;
            cout << "Thanks for playing!" << endl;
            cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
            return 0;
        }



        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {   //if the response is yes do this
                // continue playing

                discardPile.addCard(user);         //adding user card to the discardPile
                discardPile.addCard(computer);      //adding computer card to the discardPile

                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {  //if the response is no do this
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {                                     //if the response isn't valid
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