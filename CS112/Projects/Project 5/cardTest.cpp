#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "CreatureCard.h"
#include "LandCard.h"


using namespace std;

int main() {
    srand(time(0));

    cout << boolalpha;

    cout << "*****TESTING GameCard CLASS*****" << endl;

    cout << "TESTING Zero Argument Constructor" << endl;
    GameCard *TokenPtr = new GameCard();
    TokenPtr->display();
    TokenPtr->setName("Copter");

    cout << (TokenPtr->getName() == "Copter") << endl;
    cout << (TokenPtr->getColor() == None) << endl;

    cout << "*****TESTING CreatureCard CLASS*****" << endl;

    cout << "TESTING Random Constructor" << endl;
    CreatureCard Mark = CreatureCard("Mark", Blue);
    Mark.display();
    cout << Mark.toString() << endl;

    cout << "TESTING Full Constructor" << endl;
    CreatureCard *NolanPtr = new CreatureCard("Nolan", Red, 6, 9, 9);
    NolanPtr->display();
    cout << NolanPtr->toString() << endl;

    cout << "TESTING Stat Caps on Variables" << endl;
    CreatureCard *WildeBeastPtr = new CreatureCard("WildeBeast", Green, 15, 17, 9000);
    WildeBeastPtr->display();
    cout << WildeBeastPtr->toString() << endl;

    cout << "*****TESTING LandCard CLASS*****" << endl;
    LandCard *PlainsLandPtr = new LandCard("Plains", White, 1);
    PlainsLandPtr->display();
    cout << PlainsLandPtr->toString() << endl;

}
