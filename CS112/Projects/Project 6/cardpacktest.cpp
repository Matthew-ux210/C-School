#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "CardPack.h"

using namespace std;

int main() {
    srand(time(0));

    cout << boolalpha;

    cout << "*****TESTING GameCard CLASS*****" << endl;

    GameCard *TokenPtr = new GameCard();
    TokenPtr->display();
    TokenPtr->setName("Copter");

    cout << "*****TESTING CreatureCard CLASS*****" << endl;

    CreatureCard Mark = CreatureCard("Mark", Blue);
    Mark.display();
    cout << Mark.toString() << endl;

    cout << "*****TESTING LandCard CLASS*****" << endl;
    LandCard *PlainsLandPtr = new LandCard("Plains", White, 1);
    PlainsLandPtr->display();
    cout << PlainsLandPtr->toString() << endl;

    cout << "*****TESTING CardPack Class*****" << endl;
    CardPack *CardPackPtr = new CardPack();
    CardPackPtr->display();

}
