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
    cardCost = DEFAULT_COST;
    cardPower = DEFAULT_POWER;
    cardToughness = DEFAULT_TOUGHNESS;
}

//RANDOM CONSTRUCTOR
GameCard::GameCard(string name, Color color){
    cardName = name;
    cardColor = color;
    cardCost = (rand() % 10) + 1;
    cardPower = rand() % 11;
    cardToughness = (rand() % 10) + 1;
}

//FULL CONSTRUCTOR
GameCard::GameCard(string name, Color color, int cost, int power, int toughness){
    cardName = name;
    cardColor = color;

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
string GameCard::getName() const{
    return cardName;
}

Color GameCard::getColor() const{
    return cardColor;
}

int GameCard::getCost() const{
    return cardCost;
}

int GameCard::getPower() const{
    return cardPower;
}

int GameCard::getToughness() const{
    return cardToughness;
}

//*****MUTATORS*****//
void GameCard::setName(string newName){
    cardName = newName;
}

void GameCard::setColor(Color newColor){
    cardColor = newColor;
}

void GameCard::setCost(int newCost){
    if(newCost > 0 && newCost < 11)
        cardCost = newCost;
    else
        cardCost = DEFAULT_COST;
}

void GameCard::setPower(int newPower){
    if(newPower >=0 && newPower < 11)
        cardPower = newPower;
    else
        cardPower = DEFAULT_POWER;
}

void GameCard::setToughness(int newToughness){
    if(newToughness > 0 && newToughness < 11)
        cardToughness = newToughness;
    else
        cardToughness = DEFAULT_TOUGHNESS;
}

//*****OTHER METHODS*****//
void GameCard::display(){
    cout << "*****Card Display*****" << endl;
    cout << "   Card Name Is: " << cardName << endl;
    cout << "   Card Color Is: " << COLORS[cardColor] << endl;
    cout << "   Card Cost Is: " << cardCost << endl;
    cout << "   The Cards Stats Are: " << cardPower << "/" << cardToughness << endl;

}

string GameCard::toString(){
    return "\"" + cardName + "\", "
        + "\"" + COLORS[cardColor] + "\", "
        + std::to_string(cardCost) + ", "
        + std::to_string(cardPower) + ", "
        + std::to_string(cardToughness);
}
