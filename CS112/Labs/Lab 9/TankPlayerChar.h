//  CS 112 Spring 2025 - Week 09 Lab
//  Matthew Anderson and Jesse Perez

#ifndef TANKPLAYERCHAR_H
#define TANKPLAYERCHAR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "PlayerChar.h"

using namespace std;

class TankPlayerChar: public PlayerChar{

// Constructors:
    public:
        TankPlayerChar();
        TankPlayerChar(string, Role);

// Acccessors:
        double getAggro() const;
        int getStamina() const;

// Mutators:
        void decreaseAggro(double);
        void decreaseStamina(int);
        void restoreAggro();
        void restoreStamina();

// Other Methods:
        void display() const;
        string toString() const;


    private:
        double playerAggro;
        int playerStamina;

};





#endif /* TANKPLAYERCHAR_H */

