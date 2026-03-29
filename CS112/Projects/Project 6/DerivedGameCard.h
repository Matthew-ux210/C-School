#ifndef DERIVEDGAMECARD_H
#define DERIVEDGAMECARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"

using namespace std;

//DEFAULT VARIABLES
    const int DEFAULT_COST = 1;
    const int DEFAULT_POWER = 1;
    const int DEFAULT_TOUGHNESS = 1;
    const int DEFAULT_MANA = 1;

//*****CLASS DEFENITON*****//
class CreatureCard: public GameCard {
    public:

//CONSTRUCTOR HEADERS
        CreatureCard();
        CreatureCard(string, Color);
        CreatureCard(string, Color, int, int, int);

//MUTATOR HEADERS
        void setCost(int);
        void setPower(int);
        void setToughness(int);

//ACCESSOR HEADERS
        int getCost() const;
        int getPower() const;
        int getToughness() const;

//OTHER HEADERS
        void display() const;
        string toString() const;

    private:
        int cardCost;
        int cardPower;
        int cardToughness;

};

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
