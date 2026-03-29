// CS 112 Spring 2025 - Project 01
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double ANGELA_WANDPOWER = 0.25;
double CEDRIC_WANDPOWER = 0.50;
double ELOISE_WANDPOWER = 0.75;

bool angelaActive = true;
bool cedricActive = true;
bool eloiseActive = true;

/*
    Signature: primesCalculator(int);
        but, prints all of the prime-numbers values in a range from 2 to a given value
        not using a list of pre-defined prime numbers.

    Tests:
        primesCalculator(5) prints:
        3
        5

        primeCalculator(8) prints:
        3
        5
        7
*/

void primesCalculator(int inputNum) {

    for(int currVal = 2; currVal <= inputNum; currVal++){
        bool isPrime = true;

        for(int divide = 2; divide < currVal; divide++){
            if(currVal % divide == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            cout << currVal << endl;
    }
}


/* Signature: void rochambeau();
    contains a loops that asks the user to play rock paper scissors.
    If the user responds with the upper or lower versions of R, P, or S
    the function will stack up a numeric value assigned to the char with a randonmly generated value between 1 and 3.

    if the user responds with something other than R, P, or S
    the loop breaks, and displays the number of wins, losses, and ties that occured

*/
void rochambeau() {
    int wins = 0;
    int losses = 0;
    int ties = 0;
    char userVal;
    int robVal;

    bool wBool = true;

    cout << "Time for some Rochambeau!" << endl;
    cout << "Type r for Rock, p for paper, s for scissors, and any other letter to end the game" << endl;

    while(wBool){
        robVal = rand() % 3;
        cout << "Rock, Paper, Scissors, Shoot!: ";
        cin >> userVal;

        switch(userVal){
            case 'R':
            case 'r':
                if (robVal == 0){
                    ties++;
                    cout << "User Ties" << endl;
                }
                else if(robVal == 1){
                    losses++;
                    cout << "User Loses" << endl;
                }
                else{
                    wins++;
                    cout << "User Wins" << endl;
                }

                break;

            case 'P':
            case 'p':
                if (robVal == 0){
                    wins++;
                    cout << "User Wins" << endl;

                }
                else if(robVal == 1){
                    ties++;
                    cout << "User Ties" << endl;
                }
                else{
                    losses++;
                    cout << "User Loses" << endl;
                }

                break;

            case 'S':
            case 's':
                if (robVal == 0){
                    losses++;
                    cout << "User Loses" << endl;
                }
                else if(robVal == 1){
                    wins++;
                    cout << "User Wins" << endl;
                }
                else{
                    ties++;
                    cout << "User Ties" << endl;
                }

                break;

            default:
                wBool = false;

                break;
        }
    }

    cout << "Total Wins: " << wins << endl;
    cout << "Total Losses: " << losses << endl;
    cout << "Total Ties: " << ties << endl;
}

/*
    void spell(bool&, double);
    expects a bool that represents whether someone is conscious,
    and a const double representing wand power.
    Based on the wand power, the function will have a CHANCE to "knock out" the character by setting the bool to false


*/

void spell(bool& opponentActive, double wandPower) {
    int spellCast = rand() %4;

    if(wandPower == 0.25 && spellCast == 0){
        //cout << "Hit" << endl;
        opponentActive = false;
    }

    else if(wandPower == 0.50 && spellCast <= 1){
        //cout << "Hit" << endl;
        opponentActive = false;
    }

    else if(wandPower == 0.75 && spellCast <= 2){
        //cout << "Hit" << endl;
        opponentActive = false;
    }


}


/*
Signature: int startDuel();
runs a while loop that checks how many of the 3 wizards are left standing
if more than one is left, has each of the standing wizards cast an attack on the others using the spell() function
*/

int startDuel() {

    double ANGELA_WANDPOWER = 0.25;
    double CEDRIC_WANDPOWER = 0.50;
    double ELOISE_WANDPOWER = 0.75;

    bool angelaActive = true;
    bool cedricActive = true;
    bool eloiseActive = true;

    while((angelaActive + cedricActive + eloiseActive) > 1){

        if (angelaActive) {
            if (cedricActive)
                spell(cedricActive, ANGELA_WANDPOWER);

            if (eloiseActive)
                spell(eloiseActive, ANGELA_WANDPOWER);
        }

        if (cedricActive) {
            if (angelaActive)
                spell(angelaActive, CEDRIC_WANDPOWER);
            if (eloiseActive)
                spell(eloiseActive, CEDRIC_WANDPOWER);
        }

        if (eloiseActive) {
            if (angelaActive)
                spell(angelaActive, ELOISE_WANDPOWER);
            if (cedricActive)
                spell(cedricActive, ELOISE_WANDPOWER);
        }
    }

    if (angelaActive)
        return 0;
    if (cedricActive)
        return 1;

    return 2;
}


