// CS 112 Spring 2025 - Week 01 Lab
// Matthew Anderson

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * get_restaurants: string[] int -> void
 * Expects an array intended to hold restaurant names and its size
 * Returns nothing
 * Side effects:
 *     *   Asks the user for the specific number of restaurant names
 *     *   Mutates the array to store those names
 *
 * tests:
 *     if you have:
 *         const int NUM_DIVES = 3;
 *         string dives[NUM_DIVES];
 *
 *     and if you then call:
 *         get_restaurants(dives, NUM_DIVES);
 *
 *      then it should prompt the user for 3 restaurant names,
 *      and if the user happens to enter:
 *
 *      First's
 *      Dave's
 *      Mickey Diner
 *
 *      then after this call, the array dives should contain:
 *
 *      { "First's", "Dave's", "Mickey Diner" }
 *
 *      if you have:
 *          const int NUM_FAVES = 4;
 *          string faves[NUM_FAVES];
 *
 *      and if you then call:
 *          get_restaurants(faves, NUM_FAVES);
 *
 *      then it should prompt the user for 4 restaurant names,
 *      and if the user happens to enter:
 *
 *      Tony's
 *      Obento
 *      Arcata Scoop
 *      Venicia
 *
 *      then after this call, faves should contain:
 *
 *      { "Tony's", "Obento", "Arcata Scoop", "Venezia" }
 */

void get_restaurants(string restaurants[], int size) {
    // Ask the user to enter restaurant names to fill the
    // given array

   for (int i=0; i < size; i++) {
       cout << "Enter restaurant name #" << i+1 << ": ";
       getline(cin, restaurants[i]);
   }

   // You do NOT use a return statement in a void function!
}

