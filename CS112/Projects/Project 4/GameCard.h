#ifndef GAMECARD_H
#define GAMECARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//*****ENUM DATA TYPES*****//
//CARD COLOR
    enum Color {Red, Blue, Green, Black, White, None};

//CARD TYPE
    //enum cardType = {Land, Creature, Sorcery};

//*****CONSTANT VARIABLES*****//
    const string COLORS[] = {"Red", "Blue", "Green", "Black", "White", "None"};

//DEFAULT VARIABLES
    const string DEFAULT_NAME = "Token";
    const Color DEFAULT_COLOR = None;
    const int DEFAULT_COST = 1;
    const int DEFAULT_POWER = 1;
    const int DEFAULT_TOUGHNESS = 1;

//*****CLASS DEFENITON*****//
    class GameCard{
        public:

//CONSTRUCTOR HEADERS
        GameCard();
        GameCard(string, Color);
        GameCard(string, Color, int, int, int);

//ACCESSOR HEADERS
        string getName() const;
        Color getColor() const;
        int getCost() const;
        int getPower() const;
        int getToughness() const;

//MUTATOR HEADERS
        void setName(string);
        void setColor(Color);
        void setCost(int);
        void setPower(int);
        void setToughness(int);

//OTHER HEADERS
        void display();
        string toString();


        private:
        string cardName;
        Color cardColor;
        int cardCost;
        int cardPower;
        int cardToughness;

};

#endif
