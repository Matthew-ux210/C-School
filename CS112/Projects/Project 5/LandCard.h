#ifndef LANDCARD_H
#define LANDCARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"

using namespace std;

//DEFAULT VARIABLES
    const int DEFAULT_MANA = 1;

//*****CLASS DEFENITON*****//
class LandCard: public GameCard {
    public:

//CONSTRUCTOR HEADERS
        LandCard();
        LandCard(string, Color, int);

//MUTATOR HEADERS
        void setMana(int);

//ACCESSOR HEADERS
        int getMana() const;

//OTHER HEADERS
        void display() const;
        string toString() const;

    private:
        int cardMana;

};
#endif
