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

//*****CONSTANT VARIABLES*****//
    const Color COLOR_VALUES[6] = {Red, Blue, Green, Black, White, None};
    const string COLOR_NAMES[6] = {"Red", "Blue", "Green", "Black", "White", "None"};

//DEFAULT VARIABLES
    const string DEFAULT_NAME = "Token";
    const Color DEFAULT_COLOR = None;

//*****CLASS DEFENITON*****//
    class GameCard{
        public:

//CONSTRUCTOR HEADERS
        GameCard();
        GameCard(string, Color);

//ACCESSOR HEADERS
        string getName() const;
        Color getColor() const;

//MUTATOR HEADERS
        void setName(string);
        void setColor(Color);

//OTHER HEADERS
        void display() const;
        string toString() const;


        private:
        string cardName;
        Color cardColor;
};

#endif
