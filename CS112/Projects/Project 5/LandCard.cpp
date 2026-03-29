#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "LandCard.h"

using namespace std;

//*****CONSTRUCTORS*****/

//DEFAULT CONSTRUCTOR
LandCard::LandCard() : GameCard() {
    cardMana = DEFAULT_MANA;

}

//FULL CONSTRUCTOR
LandCard::LandCard(string name, Color color, int mana) : GameCard(name, color) {
    cardMana = mana;
}

//*****ACCESSORS*****//
int LandCard::getMana() const{
    return cardMana;
}

//*****MUTATORS*****//
void LandCard::setMana(int mana){
    cardMana = mana;
}

//*****OTHER METHODS*****//
void LandCard::display() const{
    cout << "=============================" << endl;
    GameCard::display();
    cout << "-----------------------------" << endl;
    cout << " Mana Value: " << cardMana << endl;
    cout << "=============================" << endl << endl;
}


string LandCard::toString() const{
    return this->GameCard::toString() + "\""
    + std::to_string(cardMana);
}
