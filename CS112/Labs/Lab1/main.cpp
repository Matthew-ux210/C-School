// CS 112 Spring 2025 - Week 01 Lab
// Matthew Anderson


#include <cstdlib>
#include <iostream>
#include <string>
#include "get_restaurants.h"

using namespace std;

int main() {
    cout << boolalpha;

    //     The testing of get_restaurants will be interactive.
    //     When testing get_restaurants in the main function,
    //     things get a BIT more involved, because we need
    //     to somehow SHOW the now-filled argument array!

    cout << endl;
    cout << "*** Testing get_restaurants ***" << endl;

    // declare an example argument array to be filled by get_restaurants

    const int NUM_RESTAURANTS = 3;
    string nameArray[NUM_RESTAURANTS];

    // and give user the "instructions" for this test

    cout << endl;
    cout << "PLEASE enter " << endl
         << "    First's - Dave's - Mickey Diner " << endl
         << "when asked:"
         << endl << endl;

    // NOTE how you call a void function!
    // NOT using a cout! NOT using an assignment statement!
    // And it has NO return value!

    get_restaurants(nameArray, NUM_RESTAURANTS);

    // Now show user the contents of nameArray[], to see if get_restaurants
    // filled it correctly:

    cout << endl;
    cout << "nameArray[] should NOW contain the names you entered; does it?"
         << endl << "============" << endl;

    for (int i=0; i < NUM_RESTAURANTS; i++) {
        cout << nameArray[i] << endl;
    }
    cout << endl;

    // and here is the 2nd test of get_restaurants

    const int NUM_FAVES = 4;
    string faves[NUM_FAVES];

    cout << "PLEASE enter 4 of your favorite places"
         << endl << endl;

    get_restaurants(faves, NUM_FAVES);

    cout << endl;
    cout << "faves should NOW contain THOSE names; does it?" << endl
         << "============" << endl;

    for (int i = 0; i < NUM_FAVES; i++) {
        cout << faves[i] << endl;
    }

    return EXIT_SUCCESS;
}

