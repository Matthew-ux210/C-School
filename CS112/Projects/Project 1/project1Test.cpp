// CS 112 Spring 2025 - Project 01 test file
// By David C. Tuttle
//
// DO NOT TURN IN THIS FILE!
// Students are free to add more tests to this file,
// but it is NOT to be submitted with the Project 1
// submission.  ONLY project1.cpp IS TO BE SUBMITTED!

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "project1.h"

using namespace std;

// NAMED CONSTANTS for main() go here

// NUM_TESTS is the number of calls made to some
// functions for testing.  You can set this number
// to a much lower value for initial tests, then set
// it back to a high number for final testing
const int NUM_TESTS = 1000;


// The following is a "helper" function written by
// the instructor to conduct some of the tests

// runSpellTests: double -> void
// Expects a probability value from 0.0 to 1.0
// Returns nothing
// Side effects: Calls the spell(bool&, double) function
//     the number of times set in NUM_TESTS and with the
//     passed probability value as a double parameter.
//     Reports number of times the spell function sets
//     the bool to true or false.  This function can
//     be used to verify correct execution of spell.
// NOTE: Results should be VERY CLOSE TO the probaility,
//       but we have random values so it won't be exact

void runSpellTests(double spellProbability) {
    int numTrue = 0;
    int numFalse = 0;
    bool boolValue = true;

    cout << "Running " << NUM_TESTS << " tests: " << endl;

    for (int i=0; i < NUM_TESTS; i++) {
        boolValue = true;
        spell(boolValue, spellProbability);
        if (boolValue) {
            numTrue++;
        }
        else {
            numFalse++;
        }
    }
    cout << "  At probability " << spellProbability
         << ", results were: "
         << numTrue << " Failures, "
         << numFalse << " Successes" << endl;
    cout << "  Success rate: " << 100.0*numFalse/NUM_TESTS << "%"
         << endl << endl;
}


int main() {
    cout << boolalpha;

    // "Seed" (initialize) the random number generator once
    // for use by all functions that use rand()
    // NOTE: Do NOT put srand() in ANY function!  Use only
    // rand() to generate a random integer value
    // from 0 to 32767 when needed
    srand(time(NULL));

    // PROBLEM 1
    cout << "*** TESTING primesCalculator ***" << endl;

    int inputNum = 0;
    cout << "Enter a number to generate primes less than or equal to it" << endl
         << "    (enter 0 to exit): ";
    cin >> inputNum;
    while (inputNum != 0) {
        cout << "Primes <= " << inputNum << ": ";
        primesCalculator(inputNum);
        cout << endl;
        cout << "Next number (0 to exit): ";
        cin >> inputNum;
    }
    cout << endl;

    // PROBLEM 2
    cout << "*** TESTING rochambeau ***" << endl;

    char yn = 'y';

    cout << "Wish to test rochambeau (y/n)? ";
    cin >> yn;
    while (yn == 'y') {
        rochambeau();
        cout << "Test again (y/n)? ";
        cin >> yn;
    }

    cout << endl;

    // PROBLEM 3
    cout << "*** TESTING spell ***" << endl;

    runSpellTests(0.25);
    runSpellTests(0.50);
    runSpellTests(0.75);

    cout << endl;

    // PROBLEM 4
    cout << "*** TESTING startDuel ***" << endl;

    int winCount[3] = {0,0,0};

    cout << "Time to run " << NUM_TESTS << " duels!" << endl;
    for (int i=0; i<NUM_TESTS; i++) {
        winCount[startDuel()]++;
    }

    cout << "  *** Duel stats ***" << endl
         << "    Wins for Angela: " << winCount[0] << endl
         << "    Wins for Cedric: " << winCount[1] << endl
         << "    Wins for Eloise: " << winCount[2] << endl
         << "  Angela won " << 100*winCount[0]/NUM_TESTS << "%" << endl
         << "  Cedric won " << 100*winCount[1]/NUM_TESTS << "%" << endl
         << "  Eloise won " << 100*winCount[2]/NUM_TESTS << "%" << endl
         << endl;

    return EXIT_SUCCESS;
}
