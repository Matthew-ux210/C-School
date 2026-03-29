#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "CardPack.h"

using namespace std;

//*****CONSTRUCTORS*****//

//DEFAULT CONSTRUCTOR
CardPack::CardPack() {
    packName = DEFAULT_PACK_NAME;
    packSize = DEFAULT_SIZE;
    packCapacity = DEFAULT_CAPACITY;

    cards = new CreatureCard[packCapacity];

    for(int i = 0; i < packSize; i++){
        string name = CARDNAMES[rand() % 9];
        Color color = COLOR_VALUES[rand() % 7];
        cards[i] = CreatureCard(name, color);
    }
}

//FULL CONSTRUCTOR
CardPack::CardPack(string name, int size, int capacity) {
    packName = name;

    if(size <= capacity)
        packSize = size;
    else
        packSize = packCapacity;

    packCapacity = capacity;

    cards = new CreatureCard[packCapacity];

        for(int i = 0; i < packSize; i++){
        string name = CARDNAMES[rand() % 8];
        Color color = COLOR_VALUES[rand() % 6];
        cards[i] = CreatureCard(name, color);
        }
}

//DESTRUCTOR
CardPack::~CardPack() {
    delete[] cards;
}

//*****ACCESSORS*****//
string CardPack::getPackName() const{
    return packName;
}

int CardPack::getPackSize() const{
    return packSize;
}

int CardPack::getPackCapacity() const{
    return packCapacity;
}

//*****MUTATORS*****//
void CardPack::setPackName(string name){
    packName = name;
}

void CardPack::setPackSize(int size){
    packSize = size;
}

void CardPack::setPackCapacity(int capacity){
    packName = capacity;
}

//*****OTHER METHODS*****//

void CardPack::display() const{
    cout << "Card Pack Name: " << packName << endl;
    cout << "Pack Size: " << packSize << endl;
    cout << "Pack Capacity: " << packCapacity << endl;
    cout << " " << endl;

    for(int i = 0; i < packSize; i++){
        cards[i].display();
        cout << " " << endl;
    }
}
