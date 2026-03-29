//  CS 112 Spring 2025 - Week 10 Lab

#ifndef TANKPLAYERCHAR_H
#define TANKPLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "PlayerChar.h"

using namespace std;

// NAMED CONSTANTS

// The NARRATION boolean can be used to turn on
// "commentary" within a method in TankPlayerChar.
// This can be useful for debugging and testing,
// and for keeping your methods "quiet" when they're
// run thousands of times.

// When writing your code in the methods
// for the TankPlayerChar class, place *all* cout
// statements in if blocks like this:

// if (NARRATION) {
//     cout << [whatever you're writing to the screen];
// }

// When NARRATION is set to false, please be sure that
// *no* output from the methods goes to the screen!

const bool NARRATION = false;

// Definition of derived class TankPlayerChar goes here

class TankPlayerChar: public PlayerChar {
  public:
    // CONSTRUCTORS
    TankPlayerChar();
    TankPlayerChar(string, Role);

    // ACCESSORS
    double getAggro() const;
    int getStamina() const;

    // MUTATORS
    void decreaseAggro(double);
    void decreaseStamina(int);
    void restoreAggro();
    void restoreStamina();

    // OTHER METHODS
    void display() const;
    string toString() const;

    // NEW METHODS FOR THIS LAB
    double rollForDamage() const;
    bool battle(TankPlayerChar&);

  private:
    double playerAggro;
    int playerStamina;
};

#endif /* TANKPLAYERCHAR_H */

