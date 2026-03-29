#ifndef CARDPACK_H
#define CARDPACK_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "DerivedGameCard.h"

using namespace std;

//DEFAULT VARIABLES
const string DEFAULT_PACK_NAME = "Booster Pack";
const int DEFAULT_SIZE = 15;
const int DEFAULT_CAPACITY = 15;

enum CardNames {Wizard, Knight, Beast, Archer, Merfolk, Shaman, Goblin, Bezerker};

const string CARDNAMES[] = {"Wizard", "Knight", "Beast", "Archer", "Merfolk", "Shaman", "Goblin", "Bezerker"};

//*****CLASS DEFENITON*****//
class CardPack {
    public:

//CONSTRUCTOR HEADERS
        CardPack();
        CardPack(string,int,int);

//MUTATOR HEADERS
        void setPackName(string);
        void setPackSize(int);
        void setPackCapacity(int);

//ACCESSOR HEADERS
        string getPackName() const;
        int getPackSize() const;
        int getPackCapacity() const;

//OPERATORS
        ~CardPack();

//OTHER HEADERS
        void display() const;
        string toString() const;

    private:
        string packName;
        int packSize;
        int packCapacity;
        CreatureCard* cards;

};

#endif
