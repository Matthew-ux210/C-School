//  CS 112 Spring 2025 - Week 09 Lab
//  MAtthew Anderson and Jesse Perez

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "TankPlayerChar.h"

using namespace std;

// CONSTRUCTORS
TankPlayerChar::TankPlayerChar() : PlayerChar(){
    playerAggro = (getStrength() * getAgility())/2.0;
    playerStamina = getStrength()/2;
}
TankPlayerChar::TankPlayerChar(string name, Role newRole): PlayerChar(name, newRole){
    playerAggro = (getStrength() * getAgility())/2.0;
    playerStamina = getStrength()/2;
}

// ACCESSORS

double TankPlayerChar::getAggro() const{
    return playerAggro;
}

int TankPlayerChar::getStamina() const{
    return playerStamina;
}


// MUTATORS
void TankPlayerChar::decreaseAggro(double amount){
    if (amount < playerAggro)
        playerAggro -= amount;
    if (amount >= playerAggro)
        playerAggro = 0;
}

void TankPlayerChar::decreaseStamina(int amount){
    if (amount >= 0)
    playerStamina -= amount;
}

void TankPlayerChar::restoreAggro(){
    playerAggro = (getStrength() * getAgility())/2.0;
}

void TankPlayerChar::restoreStamina(){
    playerStamina = getStrength()/2;
}


// OPERATOR METHODS
void TankPlayerChar::display() const{
    this->PlayerChar::display();
    cout << "AGGRO IS " << playerAggro << endl
    << "STAMINA IS  " << playerStamina << endl;
}

string TankPlayerChar::toString() const {
    return this->PlayerChar::toString() + "\""
         + std::to_string(playerAggro)
         + std::to_string(playerStamina);
}


// OTHER METHODS
double TankPlayerChar::rollForDamage() const{
    int d20 = (rand() % 21);

    return (d20 * 0.05);
}

bool TankPlayerChar::battle(TankPlayerChar& Opponent) {
    //cout << "Commencing Battle!!!" << endl;

    while (Opponent.getAggro() > 0 && this->getAggro() > 0) {

        if (NARRATION)
            cout << "Commencing Battle!" << endl;

        double playerAttack = rollForDamage() * this->getAggro();
        double opponentAttack = rollForDamage() * Opponent.getAggro();

        Opponent.decreaseAggro(playerAttack);
        this->decreaseAggro(opponentAttack);

        if (NARRATION) {
            cout << "- BEGIN ROUND! -" << endl;
            cout << this->getName() << " inflicts " << playerAttack << " damage on " << Opponent.getName() << "!!!" << endl;
            cout << Opponent.getName() << " inflicts " << opponentAttack << " damage on " << this->getName() << "!!!" << endl;
            cout << this->getName() << " has " << this->getAggro() << " aggro remaining" << endl;
            cout << Opponent.getName() << " has " << Opponent.getAggro() << " aggro remaining" << endl;
        }
    }

    if (NARRATION)
        cout << "Battle Over" << endl;

    return Opponent.getAggro() <= 0;
}




