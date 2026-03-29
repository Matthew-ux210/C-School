#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "GameCard.h"

using namespace std;

int main() {
    srand(time(0));

    cout << boolalpha;

    cout << "*****TESTING GameCard CLASS*****" << endl;

    cout << "TESTING Zero Argument Constructor" << endl;
    GameCard *TokenPtr = new GameCard();
    TokenPtr->display();
    TokenPtr->setName("Copter");
    TokenPtr->setColor(White);
    TokenPtr->setCost(2);
    TokenPtr->setPower(2);
    TokenPtr->setToughness(2);

    cout << (TokenPtr->getName() == "Copter") << endl;
    cout << (TokenPtr->getColor() == White) << endl;
    cout << (TokenPtr->getPower() == 2) << endl;
    cout << (TokenPtr->getToughness() == 2) << endl;
    cout << TokenPtr->toString() << endl;

    cout << "TESTING Random Constructor" << endl;
    GameCard Mark = GameCard("Mark", Blue);
    Mark.display();
    cout << Mark.toString() << endl;

    cout << "TESTING Full Constructor" << endl;
    GameCard *NolanPtr = new GameCard("Nolan", Red, 6, 9, 9);
    NolanPtr->display();
    cout << NolanPtr->toString() << endl;

    cout << "TESTING Stat Caps on Variables" << endl;
    GameCard *WildeBeastPtr = new GameCard("WildeBeast", Green, 15, 17, 9000);
    WildeBeastPtr->display();
    cout << WildeBeastPtr->toString() << endl;

}
