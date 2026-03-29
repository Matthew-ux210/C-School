#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"


using namespace std;

//*****CONSTRUCTORS*****//

//DEFAULT CONSTRUCTOR
GameCard::GameCard(){
    cardName = DEFAULT_NAME;
    cardColor = DEFAULT_COLOR;
}

//FULL CONSTRUCTOR
GameCard::GameCard(string name, Color color){
    cardName = name;
    cardColor = color;
}

//*****ACCESSORS*****//
string GameCard::getName() const{
    return cardName;
}

Color GameCard::getColor() const{
    return cardColor;
}

//*****MUTATORS*****//
void GameCard::setName(string newName){
    cardName = newName;
}

void GameCard::setColor(Color newColor){
    cardColor = newColor;
}

//*****OTHER METHODS*****//
void GameCard::display() const{
    cout << "*****Card Display*****" << endl;
    cout << "   Card Name Is: " << cardName << endl;
    cout << "   Card Color Is: " << COLOR_NAMES[cardColor] << endl;
}

string GameCard::toString() const{
    return "\"" + cardName + "\", "
        + "\"" + COLOR_NAMES[cardColor] + "\", ";
}


