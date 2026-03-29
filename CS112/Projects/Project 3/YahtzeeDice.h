// CS 112 Spring 2025 - Project Assignment 03
//

#ifndef YAHTZEEDICE_H
#define YAHTZEEDICE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// NAMED CONSTANTS USED BY YahtzeeDice CLASS

const int DEFAULT_NUMDICE = 5;

class YahtzeeDice {
  public:

    // CONSTRUCTORS

    YahtzeeDice();      // Uses default number of dice
    YahtzeeDice(int);   // Specifies number of dice to be used

    // DESTRUCTOR

    ~YahtzeeDice();     // Deletes dynamically-allocated array

    // ACCESSORS

    int getNumDice() const;   // Returns number of dice

    // MUTATORS

    void rollDice(bool[]);         // Performs a "turn" to try to get a Yahtzee
                                   // Rolls some of the dice based on bool[]
                                   // Example: if boolean at index 1 is true,
                                   // then Die at index 1 is rolled
                                   // Example: if boolean at index 3 is false,
                                   // then Die at index 3 is NOT rolled
                                   // NOTE: bool value at index 0 is ignored

    // OTHER METHODS

    void display() const;          // Displays like this --> 6 4 3 5 1
    string toString() const;       // Returns string like this --> "6 4 3 5 1 "
    int getValue(int);             // Returns dieValue of Die at that index in array
    int mostCommonValue();         // Returns most common value found on the dice
    bool isYahtzee();              // Returns true if all dice values match
    int yahtzeeTest();             // Performs a Yahtzee test as in Project #2
                                   // Returns number of turns needed to get a
                                   // Yahtzee (or 2*numDice + 1 if no Yahtzee)

  private:

    int numDice;                   // Number of dice being used
    Die *diceArray;                // Name of array to be dynamically allocated
                                   // in constructor (and deleted in destructor)
};

#endif /* YAHTZEEDICE_H */

