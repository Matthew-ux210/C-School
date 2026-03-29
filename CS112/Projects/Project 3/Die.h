// CS 112 Spring 2025 - Project Assignment 03
//

#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// NAMED CONSTANTS USED BY Die CLASS

const int DEFAULT_SIDES = 6;   // Default number of sides on Die

class Die {
  public:

    // CONSTRUCTORS

    Die();    // Uses DEFAULT_SIDES constant, sets dieValue to 0
    Die(int); // Specified number of sides, sets dieValue to 0

    // ACCESSORS

    int getSides() const;     // Gets number of sides
    int getValue() const;     // Gets last rolled value

    // MUTATORS

    void roll();              // Rolls the Die, updates dieValue

    // OTHER METHODS

    void display() const;     // Example: Displays "6 " for a dieValue of 6
    string toString() const;  // Example: Returns string "6 " for a dieValue of 6

  private:

    int dieSides;             // Number of sides the Die has
    int dieValue;             // Last rolled value of the Die (0 when created)
};


#endif /* DIE_H */

