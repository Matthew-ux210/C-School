// CS 112 Spring 2025 - Project Assignment 03
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Die.h"

using namespace std;

// CONSTRUCTORS

Die::Die() {
    dieSides = DEFAULT_SIDES;
    dieValue = 0;
}

Die::Die(int sides) {
    dieSides = sides;
    dieValue = 0;
}

// ACCESSORS

int Die::getSides() const {
    return dieSides;
}

int Die::getValue() const {
    return dieValue;
}

// MUTATORS

void Die::roll() {
    dieValue = rand() % dieSides + 1;
}

// OTHER METHODS

void Die::display() const {
    cout << dieValue << " ";
}

string Die::toString() const {
    return std::to_string(dieValue);
    + " ";
}

