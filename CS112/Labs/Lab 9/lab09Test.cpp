//    CS 112 Spring 2025 - Week 09 Lab
// *** DO NOT SUBMIT THIS FILE ***
// You may write additional tests if you care to :-)

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "TankPlayerChar.h"

using namespace std;

int main() {
    cout << boolalpha;

    cout << "*** TESTING PlayerChar CLASS *** " << endl;

    // Let's create PlayerChars using dynamic allocation!

    PlayerChar *fredPtr = new PlayerChar();  // Fred the Ogre
    PlayerChar *wilmaPtr = new PlayerChar("Wilma", Elf);
    PlayerChar *bettyPtr = new PlayerChar("Betty", Valkyrie);

    fredPtr->display();
    wilmaPtr->display();
    bettyPtr->display();

    cout << "String for Fred: " << fredPtr->toString();
    cout << endl << endl;

    cout << "Wilma and Betty should be 'equal': ";
    cout << (*wilmaPtr == *bettyPtr) << endl << endl;

    // **************************************************
    // TankPlayerChar test code -- UNCOMMENT TO TEST
    // **************************************************
        cout << "*** CREATING TANKPLAYERCHARS *** " << endl;

    TankPlayerChar *barneyTankPtr = new TankPlayerChar("Barney", Sprite);
    TankPlayerChar mrSlateTank("mrSlate", Ogre);
    TankPlayerChar *dinoTankPtr = new TankPlayerChar("Dino", Orc);
    TankPlayerChar joeTank("Joe the Tank", Ogre);

    cout << "*** DISPLAYING TANKPLAYERCHARS ***" << endl;

    barneyTankPtr->display();
    mrSlateTank.display();
    (*dinoTankPtr).display();

    cout << "*** DISPLAY USING PLAYERCHAR METHOD ***" << endl;

    joeTank.PlayerChar::display();

    cout << "*** TESTING toString METHOD ***" << endl;

    cout << "String for Barney: " << barneyTankPtr->toString();
    cout << endl;
    cout << "String for mrSlate: " << mrSlateTank.toString();
    cout << endl;
    cout << "String for Dino: " << (*dinoTankPtr).toString();
    cout << endl << endl;

    cout << "*** TESTING ACCESSOR METHODS ***" << endl;

    cout << barneyTankPtr->getName() << " has Aggro "
            << barneyTankPtr->getAggro() << endl;

    cout << mrSlateTank.getName() << " has Stamina "
            << mrSlateTank.getStamina() << endl;

    cout << "*** TESTING MUTATOR METHODS ***" << endl;

    cout << "Decreasing aggro:" << endl;
    barneyTankPtr->decreaseAggro(450.0);
    mrSlateTank.decreaseStamina(80);

    cout << barneyTankPtr->getName() << " now has Aggro "
            << barneyTankPtr->getAggro() << endl;

    cout << mrSlateTank.getName() << " now has Stamina "
            << mrSlateTank.getStamina() << endl;

    cout << "Restoring aggro:" << endl;
    barneyTankPtr->restoreAggro();
    mrSlateTank.restoreStamina();

    cout << barneyTankPtr->getName() << " now has Aggro "
            << barneyTankPtr->getAggro() << endl;

    cout << mrSlateTank.getName() << " now has Stamina "
            << mrSlateTank.getStamina() << endl;

    return EXIT_SUCCESS;
}
