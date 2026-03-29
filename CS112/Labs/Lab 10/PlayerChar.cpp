//    CS 112 Spring 2025 - Week 09 Lab
// *** DO NOT EDIT OR SUBMIT THIS FILE ***


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "PlayerChar.h"

using namespace std;

// CONSTRUCTORS

PlayerChar::PlayerChar() {
    playerName = DEFAULT_NAME;
    playerRole = DEFAULT_ROLE;
    playerStrength = INIT_STRENGTH[playerRole];
    playerAgility = INIT_AGILITY[playerRole];
}

PlayerChar::PlayerChar(string name, Role role) {
    playerName = name;
    playerRole = role;
    playerStrength = INIT_STRENGTH[playerRole];
    playerAgility = INIT_AGILITY[playerRole];
}

// COPY CONSTRUCTOR AND DESTRUCTOR NOT WRITTEN
// because they're not needed (the C++ compiler
// supplies a "simple" copy constructor of its own,
// and because there are no complications like pointers
// or dynamic allocation, it'll work well enough here.)

// ACCESSORS

string PlayerChar::getName() const {
    return playerName;
}

int PlayerChar::getStrength() const {
    return playerStrength;
}

double PlayerChar::getAgility() const {
    return playerAgility;
}

Role PlayerChar::getRole() const {
    return playerRole;
}

// MUTATORS

void PlayerChar::setName(string newName) {
    playerName = newName;
}

void PlayerChar::setStrength(int newStrength) {
    playerStrength = newStrength;
}

void PlayerChar::setAgility(double newAgility) {
    playerAgility = newAgility;
}

// We will not allow a PlayerChar to change its Role
// once created, so no mutator method to do so is written

// OPERATOR METHODS

bool PlayerChar::operator ==(const PlayerChar& rhs) const {
    // For PlayerChars to be "equal", their strength and agility
    // multiplied together should be within 100 of each other
    // (though the names and Roles can be different)

    double player1Value = playerStrength * playerAgility;
    double player2Value = rhs.getStrength() * rhs.getAgility();

    return (abs(player1Value - player2Value) <= 100 );
}

// OTHER FUNCTIONS

void PlayerChar::display() const {
    cout << "*** CHARACTER INFORMATION ***" << endl
         << "CHARACTER IS " << playerName << " the "
                            << ROLENAMES[playerRole] << endl
         << "STRENGTH IS " << playerStrength << endl
         << "AGILITY IS  " << playerAgility << endl;
}

string PlayerChar::toString() const {
    return "\"" + playerName + "\", "
         + "\"" + ROLENAMES[playerRole] + "\", "
         + std::to_string(playerStrength) + ", "
         + std::to_string(playerAgility);
}

