// CS 112 Spring 2025 - Project Assignment 03
// Test file - DO NOT TURN IN!

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Die.h"
#include "YahtzeeDice.h"

using namespace std;

// DEFINED CONSTANTS

// Other value for the number of sides of the Die
// besides the default value when testing
const int OTHER_DIE_SIDES_TEST = 9;

// Number of tests to conduct
const int NUM_DIE_TESTS = 20;
const int NUM_DIE_STATS_TESTS = 1000000;
const int NUM_YAHTZEE_TESTS = 1000000;

int main() {
    cout << boolalpha;

    // "Seed" (initialize) the random number generator once
    // for use by all functions that use rand()
    // NOTE: Do NOT place this line of code anywhere else!
    srand(time(NULL));

    // ****************************************************
    // PART 1 - DIE CLASS TESTS
    // ****************************************************

    cout << "*** TESTING THE CLASS Die ***" << endl;
    cout << endl;

    // Creating a default 6-sided Die
    Die myDie;

    // For efficiency's sake, we'll get the number of sides of
    // myDie just once, instead of calling the method over and
    // over again.  This value can't change once it is set.
    int myDieSides = myDie.getSides();

    cout << "*** Tests of a " << myDieSides << "-sided Die ***" << endl;
    cout << "Die initialized to " << myDie.getValue() << endl;
    cout << "Die roll tests: ";

    // We'll do the number of rolls specified by NUM_DIE_TESTS
    for (int i=0; i<NUM_DIE_TESTS; i++) {
        myDie.roll();
        myDie.display();
    }
    cout << endl;
    cout << "toString test (should match last roll): "
         << myDie.toString() << endl;
    cout << endl;

    // Next test - a new Die with a different number of sides
    Die otherDie = Die(OTHER_DIE_SIDES_TEST);

    // For efficiency's sake, we'll get the number of sides of
    // otherDie just once, instead of calling the method over and
    // over again.  This value can't change once it is set.
    int otherDieSides = OTHER_DIE_SIDES_TEST;

    cout << "*** Tests of a " << otherDieSides << "-sided Die ***" << endl;
    cout << "Die roll tests: ";
    for (int i=0; i<NUM_DIE_TESTS; i++) {
        otherDie.roll();
        otherDie.display();
    }
    cout << endl;
    cout << "toString test (should match last roll): "
         << otherDie.toString() << endl;
    cout << endl;

    // Now let's gather stats on a huge number of rolls,
    // based on the value of NUM_DIE_STATS_TESTS.
    // First, we'll create an array to hold the counts
    // of how many times a value is rolled otherDie
    // (ignoring index 0 and using the value of the Die roll
    // as the index of the array element to be incremented)

    int *dieRollCountByValue = new int[otherDieSides + 1];
    for (int i=1; i<=otherDieSides; i++) {
        dieRollCountByValue[i] = 0;
    }

    // Let's set a range of expected rolls of each value.
    // If we do 5,000 * (number of sides) tests or more, the
    // measured results should be well within 5% of expected results
    int loRangeResult = (NUM_DIE_STATS_TESTS / otherDieSides) * 0.95;
    int hiRangeResult = (NUM_DIE_STATS_TESTS / otherDieSides) * 1.05;

    for (int i=0; i<NUM_DIE_STATS_TESTS; i++) {
        otherDie.roll();
        dieRollCountByValue[otherDie.getValue()]++;
    }
    cout << "*** Stats from " << NUM_DIE_STATS_TESTS
         << " rolls of a " << otherDieSides
         << "-sided Die ***" << endl;
    for (int i=1; i<=otherDieSides; i++) {
        cout << "Rolled a " << i << " "
             << dieRollCountByValue[i] << " times -- ";
        // If sufficient numbers of test rolls are done, we
        // can reliably measure against expected results
        // (This should be at least 5,000 * number of sides)
        if (NUM_DIE_STATS_TESTS >= 5000 * otherDieSides) {
            if (dieRollCountByValue[i] >= loRangeResult &&
                dieRollCountByValue[i] <= hiRangeResult) {
                cout << " WITHIN EXPECTED RANGE ";
            }
            else {
                cout << " *** OUT OF EXPECTED RANGE *** ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // ****************************************************
    // PART II - YAHTZEEDICE CLASS TESTS
    // ****************************************************

    cout << "*** TESTING THE CLASS YahtzeeDice ***" << endl;
    cout << endl;

    // Creating an object of YahtzeeDice with the default number
    // of dice, each having a default number of sides
    // (This will automatically call the zero-argument constructor
    // for each Die object in the array holding the dice)
    YahtzeeDice myDice;

    // For efficiency's sake, we'll get the number of dice in
    // myDice just once, instead of calling the method over and
    // over again.  This value can't change once it is set.
    int numberOfDice = myDice.getNumDice();

    cout << "*** Tests of " << numberOfDice << " dice, "
         << "each having " << DEFAULT_SIDES << " sides ***" << endl;
    cout << "Dice initialized to default values --> ";
    myDice.display();
    cout << endl;

    // Now we're going to "manually" make three rolls of the dice,
    // just like we would in a real Yahtzee game!

    // First, we'll declare an int to hold the most common value
    int mostCommon = 0;

    // Let's create a boolean array to pass to the diceRoll method
    // We'll set all the diceRoll boolean values to true, so that
    // we can start by having it roll all the dice!

    // We'll use dynamic allocation here, using the method
    // that tells us how many dice there are in myDice
    // (again, skipping index 0 as being unused)
    bool *whichDiceToRoll = new bool[numberOfDice + 1];
    for (int i=1; i<=numberOfDice; i++) {
        whichDiceToRoll[i] = true;
    }

    // Now let's do the first roll of the dice and see the values

    cout << "FIRST ROLL: Rolling all the Yahtzee dice"<< endl;
    myDice.rollDice(whichDiceToRoll);
    myDice.display();
    cout << endl;

    // Now the second rool of the dice!

    cout << "SECOND ROLL: Determining which dice to roll" << endl;

    // Let's get the most common value on the dice
    // and determine which dice to roll again, and roll them.

    // First, we'll set all dice to NOT to roll (set to false)

    for (int i=1; i<=numberOfDice; i++) {
        whichDiceToRoll[i] = false;
    }

    // Now, let's determine which dice DO need to be rolled

    mostCommon = myDice.mostCommonValue();
    cout << "Most common value on dice was " << mostCommon << endl;

    // Determine which dice are to be rolled again

    cout << "*** Rolling Dice in positions ";
    for (int i=1; i<=numberOfDice; i++) {
        if (myDice.getValue(i) != mostCommon) {
            whichDiceToRoll[i] = true;
            cout << i << " ";
        }
    }
    cout << endl;

    // Now that the dice to be rolled have been determined,
    // we simply roll the dice based on the boolean array!
    // This will perform a "turn" in our Yahtzee tests later

    myDice.rollDice(whichDiceToRoll);

    // Let's see the results after the second roll

    cout << "New dice values are: ";
    myDice.display();
    cout << endl;

    // Now, let's repeat the process with a third roll!
    // (Just copied and pasted most of the code from above :-)

    cout << "THIRD ROLL: Determining which dice to roll" << endl;

    // Again, set all dice to NOT be rolled (set to false)

    for (int i=1; i<=numberOfDice; i++) {
        whichDiceToRoll[i] = false;
    }

    // Now, let's determine which dice DO need to be rolled

    mostCommon = myDice.mostCommonValue();
    cout << "Most common value on dice was " << mostCommon << endl;

    // Determine which dice to be rolled again

    cout << "*** Rolling Dice in positions ";
    for (int i=1; i<=numberOfDice; i++) {
        if (myDice.getValue(i) != mostCommon) {
            whichDiceToRoll[i] = true;
            cout << i << " ";
        }
    }
    cout << endl;

    myDice.rollDice(whichDiceToRoll);

    // Let's see the results after the third roll

    cout << "New dice values are: ";
    myDice.display();
    cout << endl;

    // OK, so now our three rolls are done!  Did we get a Yahtzee?

    if (myDice.isYahtzee()) {
        cout << "*** WOO HOO! A YAHTZEE! ***";
    }
    else {
        cout << "*** Welp, not a Yahtzee :-(";
    }
    cout << endl << endl;

    cout << "*** TESTING THE METHOD yahtzeeTest ***" << endl;

    // Now, let's test the YahtzeeDice class with a huge number of
    // tests, just like the last project.  We should get results
    // (plus or minus a few hundred or so) that match the last project
    // for a million tests using five 6-sided dice.

    // First, we'll reuse myDice as the YahtzeeDice object
    // and make an int array to hold the test results

    int *testResults = new int[2*numberOfDice + 1];

    // Initialize the array with values of zero
    // (ignoring index 0, since we won't use it here)
    for (int i=1; i<=2*numberOfDice; i++) {
        testResults[i] = 0;
    }

    // Let's call yahtzeeTest() a bunch of times!
    int returnedFromYahtzeeTest;
    for (int i=0; i<NUM_YAHTZEE_TESTS; i++) {
        returnedFromYahtzeeTest = myDice.yahtzeeTest();
        // Just to be sure, if yahtzeeTest returns a number
        // that's too large, we don't want to crash :-)
        if (returnedFromYahtzeeTest > 2*numberOfDice + 1) {
            returnedFromYahtzeeTest = 2*numberOfDice + 1;
        }
        // Increment the test result in the tabulation
        testResults[returnedFromYahtzeeTest]++;
    }

    // Now, let's print the results of tests and
    // see how many rolls each test took!

    // Results should be close to these numbers:
    //    Number of tests with  1 roll(s): 800
    //    Number of tests with  2 roll(s): 11800
    //    Number of tests with  3 roll(s): 33000
    //    Number of tests with  4 roll(s): 54500
    //    Number of tests with  5 roll(s): 69900
    //    Number of tests with  6 roll(s): 78400
    //    Number of tests with  7 roll(s): 81800
    //    Number of tests with  8 roll(s): 80200
    //    Number of tests with  9 roll(s): 75500
    //    Number of tests with 10 roll(s): 69500
    //    Number of tests with 11 roll(s): 475000
    // (That last value is large because it represents
    //  all tests where a Yahtzee didn't occur after
    //  10 rolls)

    for (int i=1; i<=2*numberOfDice + 1; i++) {
        cout << " Number of tests that resulted in ";
        if (i < 10) {
            cout << " ";
        }
        cout << i << " roll(s): " << testResults[i] << endl;
    }

    // Before leaving, we need to clean up after ourselves!
    // Anything that's been dynamically allocated in main()
    // should be deleted

    delete [] dieRollCountByValue;
    delete [] whichDiceToRoll;
    delete [] testResults;

    return EXIT_SUCCESS;
}
