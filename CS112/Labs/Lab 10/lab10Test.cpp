//  CS 112 Spring 2025 - Week 10 Lab
// *** DO NOT SUBMIT THIS FILE ***
// You may write additional tests if you care to :-)

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "TankPlayerChar.h"

using namespace std;

int main() {
    cout << boolalpha;
    cout << setprecision(3);

    srand(time(NULL));

    // **************************************************
    // TankPlayerChar test code -- UNCOMMENT TO TEST
    // **************************************************

    cout << "*** CREATING TANKPLAYERCHARS FOR BATTLE *** " << endl;

    TankPlayerChar oscar("Oscar", Orc);
    TankPlayerChar velma("Velma", Valkyrie);

    cout << "*** DISPLAYING TANKPLAYERCHARS ***" << endl;

    oscar.display();
    velma.display();

    // **************************************************
    // TankPlayerChar test code -- UNCOMMENT TO TEST
    // **************************************************

    cout << "*** TESTING THE rollForDamage METHOD ***" << endl;

    cout << "How many test rolls should be done? ";
    int numRolls;
    cin >> numRolls;
    int rollResult;
    int rollCount[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i=0; i < numRolls; i++) {
        rollResult = (oscar.rollForDamage() + 0.01) * 20;
        rollCount[rollResult]++;
    }
    cout << "(NOTE: There should be no rolls for 0 percent damage)" << endl
         << "(      and all other amounts should be near equal   )" << endl;
    for (int i=0; i <= 20; i++) {
        cout << "Rolls for " << i * 5 << " percent damage = "
             << rollCount[i] << endl;
    }
    cout << endl;

    cout << "*** PREPARE FOR BATTLES! ***" << endl;

    cout << "How many battles should the Tanks fight?: ";
    int numBattles;
    cin >> numBattles;

    cout << "*** BATTLES COMMENCING! ***" << endl;
    int oscarWins = 0;
    int velmaWins = 0;

    for (int i=0; i < numBattles; i++) {
        if (oscar.battle(velma)) {
            oscarWins++;
        }
        else {
            velmaWins++;
        }
        oscar.restoreAggro();
        velma.restoreAggro();
    }

    cout << "*******************************" << endl;
    cout << "*** FINAL STATS FOR BATTLES" << endl;
    double winPct = (oscarWins * 100.0) / (oscarWins + velmaWins);
    cout << "*** Oscar won " << oscarWins << " battles "
         << "(" << winPct << "%)" << endl;
    winPct = (velmaWins * 100.0) / (oscarWins + velmaWins);
    cout << "*** Velma won " << velmaWins << " battles "
         << "(" << winPct << "%)" << endl;

    if (oscarWins > velmaWins)
        cout << "*** OSCAR THE ORC REIGNS SUPREME!!! ***";
    else if (velmaWins > oscarWins)
        cout << "*** VELMA THE VALKYRIE REIGNS SUPREME!!! ***";
    else
        cout << "*** IT'S A TIE!!! ***";

    cout << endl;

    return EXIT_SUCCESS;
}
