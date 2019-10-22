#include <iostream>
#include <string>
#include <time.h>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));

    //Card *c1 = new Card("6", "Spades");
   // Card *c2 = new Card("5", "Hearts");

   int randomRank = rand() % 13;
   int randomSuit = rand() % 4;

    Card *user = new Card(ranks[randomRank], suits[randomSuit]);
    cout << "rank" << randomRank << "Suit" << randomSuit << endl;

    randomRank = rand() % 13;
    randomSuit = rand() % 4;
    Card *computer = new Card(ranks[randomRank], suits[randomSuit]);

    cout << "This is for computer card" << endl;
    cout << "rank" << randomRank << " Suit" << randomSuit << endl;


    if(*user < computer){
        cout << "Its Working " << endl;
    }
    else{
        cout << "Not Working " << endl;
    }
    play = true;
    while(play) {
        // assign values to computer and user
        compValue = rand() % 52;
        userValue = rand() % 52;

        // get user's bet
        cout << "Computer's value is " << compValue << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
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
        if((compValue < userValue && guessedHigher) || (compValue > userValue && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((compValue > userValue && guessedHigher) || (compValue < userValue && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << userValue << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
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