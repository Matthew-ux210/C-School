#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "DerivedGameCard.h"

using namespace std;

//*****CONSTRUCTORS*****//

//DEFAULT CONSTRUCTOR
CreatureCard::CreatureCard() : GameCard() {
    cardCost = DEFAULT_COST;
    cardPower = DEFAULT_POWER;
    cardToughness = DEFAULT_TOUGHNESS;
}

//RANDOM CONSTRUCTOR
CreatureCard::CreatureCard(string name, Color color) : GameCard(name, color) {
    cardCost = (rand() % 10) + 1;
    cardPower = rand() % 11;
    cardToughness = (rand() % 10) + 1;
}

//FULL CONSTRUCTOR
CreatureCard::CreatureCard(string name, Color color, int cost, int power, int toughness) : GameCard(name, color) {
    if(cost > 0 && cost < 11)
        cardCost = cost;
    else
        cardCost = DEFAULT_COST;

    if(power >=0 && power < 11)
        cardPower = power;
    else
        cardPower = DEFAULT_POWER;

    if(toughness > 0 && toughness < 11)
        cardToughness = toughness;
    else
        cardToughness = DEFAULT_TOUGHNESS;
}

//*****ACCESSORS*****//
int CreatureCard::getCost() const{
    return cardCost;
}

int CreatureCard::getPower() const{
    return cardPower;
}

int CreatureCard::getToughness() const{
    return cardToughness;
}

//*****MUTATORS*****//
void CreatureCard::setCost(int newCost){
    if(newCost > 0 && newCost < 11)
        cardCost = newCost;
    else
        cardCost = DEFAULT_COST;
}

void CreatureCard::setPower(int newPower){
    if(newPower >=0 && newPower < 11)
        cardPower = newPower;
    else
        cardPower = DEFAULT_POWER;
}

void CreatureCard::setToughness(int newToughness){
    if(newToughness > 0 && newToughness < 11)
        cardToughness = newToughness;
    else
        cardToughness = DEFAULT_TOUGHNESS;
}

//*****OTHER METHODS*****//
void CreatureCard::display() const{
    cout << "=============================" << endl;
    GameCard::display();
    cout << "-----------------------------" << endl;
    cout << " Cost: " << cardCost << endl;
    cout << " Power/Toughness: " << cardPower << "/" << cardToughness << endl;
    cout << "=============================" << endl << endl;
}


string CreatureCard::toString() const{
    return this->GameCard::toString() + "\""
    + std::to_string(cardCost) + ", "
    + std::to_string(cardPower) + ", "
    + std::to_string(cardToughness);
}

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
