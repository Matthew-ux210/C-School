// CS 112 Spring 2025 - Project Assignment 03
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Die.h"
#include "YahtzeeDice.h"

using namespace std;

// CONSTRUCTORS

YahtzeeDice::YahtzeeDice() {
    numDice = DEFAULT_NUMDICE;
    // Remember, index 0 will be ignored, and
    // the Die objects at index 1 to index numDice
    // will be used
    diceArray = new Die[numDice + 1];
}

YahtzeeDice::YahtzeeDice(int num) {
    numDice = num;
    diceArray = new Die[numDice + 1];
}

// DESTRUCTOR

YahtzeeDice::~YahtzeeDice() {
    delete[] diceArray;
}

// ACCESSORS

int YahtzeeDice::getNumDice() const {
    return numDice;
}

// MUTATORS

void YahtzeeDice::rollDice(bool diceToRoll[]) {
    for (int i = 1; i <= numDice; i++){
        if (diceToRoll[i] == true)
            diceArray[i].roll();
    }
}

// OTHER METHODS

void YahtzeeDice::display() const {
    for (int i = 1; i <= numDice; i++){
        diceArray[i].display();
    }
}

string YahtzeeDice::toString() const {
    string result = "";
    for (int i = 1; i <= numDice; i++) {
        result += diceArray[i].toString() + " ";
    }
    return result;
}

int YahtzeeDice::getValue(int index) {
    return diceArray[index].getValue();
}

int YahtzeeDice::mostCommonValue() {
    int freq[diceArray->getSides()] = {0};
    int maxCount = 0;
    int maxVal = 0;

    for (int i = 1; i <= numDice; i++) {
        int currVal = diceArray[i].getValue();
        freq[currVal]++;

        if(freq[currVal] > maxCount){
            maxCount = freq[currVal];
            maxVal = currVal;
        }
        else if(freq[currVal] == maxCount){
            if (currVal > maxVal)
                maxVal = currVal;
        }
    }

    return maxVal;
}

bool YahtzeeDice::isYahtzee() {
    int firstVal = diceArray[1].getValue();
    for (int i = 2; i <=numDice; i++){
        int currVal = diceArray[i].getValue();
        if (currVal != firstVal)
            return false;
    }

    return true;
}

int YahtzeeDice::yahtzeeTest() {
    const int maxTurns = 2*(numDice)+1;

    for (int i = 1; i < maxTurns; i++){
        if (isYahtzee()) {
            return i;
        }
    }
    return maxTurns;  
}
