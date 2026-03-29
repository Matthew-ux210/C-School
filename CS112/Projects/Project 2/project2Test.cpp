// CS 112 Fall 2024 - Assignment 02 test file
// David C. Tuttle
// Last Modified: 04 Feburary 2024

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "project2.h"

using namespace std;



int main() {
    cout << boolalpha;

    // CONSTANT for the number of tests to run
    // in the main() FUNCTION

    const int NUM_TESTS = 1000000;

    // "Seed" (initialize) the random number generator once
    // for use by all functions that use rand()
    srand(time(NULL));

    // ****************************************************
    // PROBLEM 1 TESTS
    // ****************************************************

    cout << "*** TESTING THE FUNCTION rollDie ***" << endl;

    int rollValue = 0;
    int rollCount[NUM_SIDES + 1];
    // NOTE: In this code, for arrays, index 0 is not used!
    // We're making each array one bigger than the number of
    // values to be used there, so rollCount[0] is not used!
    // rollCount[1] will keep track of how many rolls of 1
    // rollCount[2] will keep track of how many rolls of 2
    // etc., all the way up to rollCount[NUM_SIDES]

    // First, initialize the array to 0 values
    for (int i=1; i<=NUM_SIDES; i++) {
        rollCount[i] = 0;
    }

    // Let's run a bunch of tests!
    for (int i=0; i<NUM_TESTS; i++) {
        // Roll a single die, which will update rollValue
        // with a random number from 1 to NUM_SIDES
        // (remember, it's a CALL BY REFERENCE function!)
        rollDie(rollValue);
        // Increment the count of how many times that
        // roll value was rolled
        rollCount[rollValue]++;
    }

    cout << "*** RESULTS of function rollDie tests ***" << endl;

    // Results should be that each number is rolled about one-sixth
    // of the time -- for a million roles, that's about 166,667
    // plus-or-minus a few thousand for each value of a 6-sided die

    for (int i=1; i<=NUM_SIDES; i++) {
        cout << "Count of rolls of " << i
             << " is " << rollCount[i] << endl;
    }
    cout << endl;

    // ****************************************************
    // PROBLEM 2 TESTS
    // ****************************************************

    cout << "*** TESTING THE FUNCTION isYahtzee ***" << endl;

    // Let's create some test cases -- it's easier to just
    // create the dice in separate arrays :-) -- and remember,
    // index 0 is not used, so we'll just put a 0 there.

    // NOTE: for dice with a different number of sides
    // you'll need to change both these values and the tests!!!
    int yahtzeeDice1[NUM_DICE + 1] = {0, 1, 2, 3, 2, 4};
    int yahtzeeDice2[NUM_DICE + 1] = {0, 6, 5, 6, 2, 5};
    int yahtzeeDice3[NUM_DICE + 1] = {0, 2, 2, 2, 2, 2};
    int yahtzeeDice4[NUM_DICE + 1] = {0, 1, 3, 5, 6, 3};

    cout << (isYahtzee(yahtzeeDice1) == false) << " ";
    cout << (isYahtzee(yahtzeeDice2) == false) << " ";
    cout << (isYahtzee(yahtzeeDice3) == true) << " ";
    cout << (isYahtzee(yahtzeeDice4) == false) << " ";
    cout << endl << endl;

    // ****************************************************
    // PROBLEM 3 TESTS
    // ****************************************************

    cout << "*** TESTING THE FUNCTION mostCommonValue ***" << endl;

    // This variable will be for the value returned
    int mostCommon = 0;

    // It's quickest to just use the dice arrays from above
    // int yahtzeeDice1[NUM_DICE + 1] = {0, 1, 2, 3, 2, 4};
    // int yahtzeeDice2[NUM_DICE + 1] = {0, 6, 5, 6, 2, 5};
    // int yahtzeeDice3[NUM_DICE + 1] = {0, 2, 2, 2, 2, 2};
    // int yahtzeeDice4[NUM_DICE + 1] = {0, 1, 3, 5, 6, 3};
    cout << (mostCommonValue(yahtzeeDice1) == 2) << " ";
    cout << (mostCommonValue(yahtzeeDice2) == 6) << " ";
    cout << (mostCommonValue(yahtzeeDice3) == 2) << " ";
    cout << (mostCommonValue(yahtzeeDice4) == 3) << " ";
    cout << endl << endl;

    // Further testing of mostCommonValue using many random rolls
    // of the dice

    // We'll reuse the rollCount array here to count which value
    // was found to be most common in these tests
    // First, reset all roll counts to 0
    for (int i=0; i<=NUM_SIDES; i++) {
        rollCount[i] = 0;
    }

    // Declare an array to hold the Yahtzee dice
    // REMEMBER: In this code, yahtzeeDice[0] is not used!

    int yahtzeeDice[NUM_DICE + 1];
    for (int i=1; i<=NUM_DICE; i++) {
        yahtzeeDice[i] = 0;
    }

    // Now let's roll all the dice a bunch of times and
    // find out which number is rolled most often each time!

    cout << "Testing commencing... " << endl;
    for (int i=0; i<NUM_TESTS; i++) {
        // Roll all the dice!
        for (int j=1; j<=NUM_DICE; j++) {
            rollDie(yahtzeeDice[j]);
        }
        // Ask which number was most common and increment
        // that in the rollCount array
        mostCommon = mostCommonValue(yahtzeeDice);
        rollCount[mostCommon]++;
    }

    // NOTE: because we prioritize the larger number when
    // examining each roll of the dice, the count will not be
    // uniform across all values, but will instead skew to
    // the larger values.  Results should be close to these
    // numbers for 5 six-sided dice rolled a million times
    // (plus or minus a few hundred):
    //    The value 1 was most common 113000 times
    //    The value 2 was most common 128000 times
    //    The value 3 was most common 144000 times
    //    The value 4 was most common 159000 times
    //    The value 5 was most common 189000 times
    //    The value 6 was most common 267000 times

    // Print the results of the tests
    cout << "*** Results of mostCommonValue tests:"
         << endl;
    for (int i=1; i<=NUM_SIDES; i++) {
        cout << "   The value " << i << " was most common "
             << rollCount[i] << " times " << endl;
    }
    cout << endl;

    // ****************************************************
    // PROBLEM 4 TESTS
    // ****************************************************

    cout << "*** TESTING THE FUNCTION yahtzeeTest ***" << endl;

    // Let's do some Yahtzee tests!
    // First, we need an array to count numbers of rolls --
    // testResults[1] will hold the number of tests that had
    // a Yahtzee after one roll, and so on.  Remember, after
    // 2*NUM_DICE rolls, it stops and returns 2*NUM_DICE + 1
    // so the return value should NOT be more than that
    // NOTE: Again, we're ignoring testResults[0]
    int testResults[2*NUM_DICE + 2];

    // Initialize the array (except index 0, which we don't use)
    for (int i=1; i<=2*NUM_DICE + 1; i++) {
        testResults[i] = 0;
    }

    // Let's call yahtzeeTest() a bunch of times and keep track
    // of the counts of the returned values

    for (int i=0; i<NUM_TESTS; i++) {
        testResults[yahtzeeTest()]++;
    }

    // Now, let's print the results of tests and
    // see how many rolls each test took!

    // Results should be close to these numbers for Yahtzee
    // tests using 5 six-sided dice done a million times
    // (plus or minus a few hundred or so):
    //    Number of tests with 1 roll(s): 800
    //    Number of tests with 2 roll(s): 11800
    //    Number of tests with 3 roll(s): 33000
    //    Number of tests with 4 roll(s): 54500
    //    Number of tests with 5 roll(s): 69900
    //    Number of tests with 6 roll(s): 78400
    //    Number of tests with 7 roll(s): 81800
    //    Number of tests with 8 roll(s): 80200
    //    Number of tests with 9 roll(s): 75500
    //    Number of tests with 10 roll(s): 69500
    //    Number of tests with 11 roll(s): 475000
    // (That last value is large because it represents
    //  all tests where a Yahtzee didn't occur after
    //  10 rolls)

    for (int i=1; i<=2*NUM_DICE; i++) {
        cout << " Number of tests that resulted in " << i
             << " roll(s): " << testResults[i] << endl;
    }
    cout << " Number of tests that didn't result in a Yahtzee: "
         << testResults[2*NUM_DICE + 1] << endl;

    return EXIT_SUCCESS;
}
