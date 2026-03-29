// CS 112 Spring 2025 - Project Assignment 02
// Matthew Anderson

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
// Because the project2.h file contains named
// constants we need to use here, it's included
#include "project2.h"

using namespace std;

// ***************************************************************
// rollDie: int& -> void
// Expects an int variable that is PASS BY REFERENCE
// Returns nothing
// Side effect: generates a random number in the range [1,NUM_SIDES]
//     that represents a "roll" of the die, and stores the roll
//     value in the passed parameter variable:
// Example: For a 6-sided die (constant NUM_SIDES = 6), a call
//     of the function rollDie(int& dieValue) will generate an
//     integer value in the range [1,6] and set dieValue to that
//     random value

void rollDie(int& dieValue) {
    dieValue = rand() % NUM_SIDES + 1;
}

// ***************************************************************
// isYahtzee: int[] -> bool
// Expects an array representing the rolls of the Yahtzee dice
// Returns true if all the dice have the same value (Yahtzee!)
//     and returns false if not all dice have the same value
// NOTE: The value at index 0 in the array is ignored!

bool isYahtzee(int theDice[]) {
    for(int i = 1; i <= NUM_DICE; i++){
        if(theDice[1] != theDice[i]){
            return false;
            break;
        }
    }
    return true;
}

// ***************************************************************
// mostCommonValue: int[] -> int
// Expects an array representing the rolls of the dice
// Returns the roll value that's on the most dice
// In case of a tie (such as two dice rolled 5 and two dice
// rolled 6), the function shall return the higher of the two
// rolls that is most common (in this example, 6)
// NOTE: The value at index 0 in the array is ignored!

int mostCommonValue(int theDice[]) {
    int frequency[NUM_SIDES + 1] = {0};
    int maxCount = 0;
    int maxValue = 0;


    for (int i = 1; i <= NUM_DICE; i++) {
        int currVal = theDice[i];
        frequency[currVal]++;

        if (frequency[currVal] > maxCount) {
            maxCount = frequency[currVal];
            maxValue = currVal;
        } else if (frequency[currVal] == maxCount) {
            if (currVal > maxValue) {
                maxValue = currVal;
            }
        }
    }

    return maxValue;
}


// ***************************************************************
// yahtzeeTest: void -> int
// Expects nothing
// Returns the of turns it took to get a Yahtzee (or the value
//     2*NUM_DICE + 1 is not Yahtzee seen after 2*NUM_DICE turns)
// Side effect: declares an array for the Yahtzee dice and performs
//     the test by rolling the appropriate dice in each turn until
//     a Yahtzee is found, keeping track of the number of turns.
//     NOTE: your code MUST make use of the other functions!
// EXAMPLE:
//     Turn #1 - all dice are rolled
//         The dice now show 3 5 6 5 6, not a Yahtzee
//     Turn #2 - 6 is most common, so all dice that are not 6 are re-rolled
//         The dice now show 6 1 6 4 6, not a Yahtzee
//     Turn #3 - 6 is most common, so all dice that are not 6 are re-rolled
//         The dice now show 6 6 6 2 6, not a Yahtzee
//     Turn #4 - 6 is most common, so all dice that are not 6 are re-rolled
//          The dice now show 6 6 6 6 6 -- a Yahtzee!
//     It took 4 turns, so the function returns the value 4
//
// IMPORTANT NOTE: Check for the most common value after each turn, but NOT
//     in the middle of a turn - choose all dice to re-roll based on the most
//     common value at the beginning of the turn!
//
// If the number of turns becomes 2*NUM_DICE and a Yahtzee has not
// occurred, stop the turns and just return the value 2*NUM_DICE + 1

int yahtzeeTest() {
    int theDice[NUM_DICE + 1];
    int turns = 0;
    const int maxTurns = 2 * NUM_DICE;

    for (int i = 1; i <= NUM_DICE; i++) {
        rollDie(theDice[i]);
    }

    while (turns < maxTurns) {
        turns++;

        if (isYahtzee(theDice)) {
            return turns;
        }

        int commonValue = mostCommonValue(theDice);

        for (int i = 1; i <= NUM_DICE; i++) {
            if (theDice[i] != commonValue) {
                rollDie(theDice[i]);
            }
        }
    }

    return maxTurns + 1;
}
