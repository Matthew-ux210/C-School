// CS 112 Spring 2025 Week 02 Lab
// Reece Dickinson AND Matthew Anderson

#include <cstdlib>
#include <iostream>
#include <string>
#include "letterGradeFunctions.h"

using namespace std;

int main() {
    cout << boolalpha;

    // Tests of describeLetterGrade

    cout << "*** Testing describeLetterGrade: ***" << endl;
    cout << (describeLetterGrade("A+") == "Outstanding achievement - Plus") << " ";
    cout << (describeLetterGrade("a") == "Outstanding achievement") << " ";
    cout << (describeLetterGrade("B") == "Commendable achievement") << " ";
    cout << (describeLetterGrade("b-") == "Commendable achievement - Minus") << " ";
    cout << (describeLetterGrade("c") == "Alright achievement") << " ";
    cout << (describeLetterGrade("C-") == "Alright achievement - Minus") << " ";
    cout << (describeLetterGrade("d") == "Below-Average achievement") << " ";
    cout << (describeLetterGrade("D+") == "Below-Average achievement - Plus") << " ";
    cout << (describeLetterGrade("G") == "Try again") << " ";
    cout << (describeLetterGrade("H+") == "Try again - Plus") << " ";
    cout << (describeLetterGrade("What?") == "Try again") << " ";
    cout << (describeLetterGrade("Awwww!") == "Outstanding achievement") << " ";
    cout << (describeLetterGrade("B+C") == "Commendable achievement - Plus") << " ";
    cout << endl;

    // Just for fun...

    string enteredGrade;

    cout << endl;
    cout << "Enter a letter grade, including + or -: " << endl;
    getline(cin, enteredGrade);

    cout << endl;
    cout << "Grade description: ";
    cout << describeLetterGrade(enteredGrade) << endl;

    // Code for further testing should be inserted here

    describeGrade();

    return EXIT_SUCCESS;
}

    // *** Example of code using "new" syntax for C++11 "for" loop ***

    // string numberWords[5] = {"one", "two", "three", "four", "five"};

    // // The variable next is declared as a string, and, in each iteration
    // // of the for loop, next is set to a different value in the string
    // // array numberWords

    // for (string next : numberWords) {
    //     cout << "next: " << next << endl;
    // }

    // // That has the same output as the following loop:

    // for (int i=0; i<5; i++) {
    //     cout << "next: " << numberWords[i] << endl;
    // }

    // // The new syntax has the advantage of not needing to know
    // // the number of items in the array when writing the loop!
