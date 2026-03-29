//    CS 112 Spring 2025 - Week 09 Lab
// *** DO NOT EDIT OR SUBMIT THIS FILE ***

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Declarations of data types and constants

// PlayerChar objects can have any name the user wants

// There are only a certain set of roles
// a PlayerChar can have - this means we'll use
// an enumerated type!

enum Role {Ogre, Sprite, Elf, Valkyrie, Orc};

// NAMED CONSTANTS

const int NUM_ROLES = 5;
const string ROLENAMES[NUM_ROLES] =
    {"Ogre", "Sprite", "Elf", "Valkyrie", "Orc"};

// Arrays for initial values of strength and stamina
// for each Role
//
// Ogre = Strength 700, Agility 2.5
// Sprite = Strength 300, Agility 5.5
// Elf = Strength 400, Agility 4.5
// Valkyrie = Strength 600, Agility 3.0
// Orc = Strength 500, Agility 3.5

const int INIT_STRENGTH[NUM_ROLES]
    = {700, 300, 400, 600, 500};
const double INIT_AGILITY[NUM_ROLES]
    = {2.5, 5.5, 4.5, 3.0, 3.5};

// Default values for a PlayerChar when not specified
const string DEFAULT_NAME = "Fred";
const Role DEFAULT_ROLE = Ogre;

// Definition of class PlayerChar

class PlayerChar {
  public:
    // Headers for constructors

    PlayerChar();
    PlayerChar(string, Role);

    // Headers for accessors

    string getName() const;
    int getStrength() const;
    double getAgility() const;
    Role getRole() const;

    // Headers for mutators

    void setName(string);
    void setStrength(int);
    void setAgility(double);

    // Headers for comparison operator method

    bool operator ==(const PlayerChar& rhs) const;

    // Headers for other functions

    void display() const;
    string toString() const;

  private:

    string playerName;
    int    playerStrength;
    double playerAgility;
    Role   playerRole;
};

#endif /* PLAYERCHAR_H */

