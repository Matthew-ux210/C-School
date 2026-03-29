// CS 112 Spring 2025 Week 02 Lab
// Reece Dickinson AND Matthew Anderson

// describeLetterGrade: string -> string
//   purpose: expects a letter grade (in the form of a string)
//       that may include + or -, and returns a text description
//       of that grade. Letter grades supported are A, B, C and D
//       (with descriptions taken from the Humboldt Course Catalog),
//       followed by " - Plus" if letter grade is followed by + and
//       followed by " - Minus" if letter grade is followed by -
//
//       (Any grade that does not start with
//       A, B, C or D will return a description of "Try again", followed by
//       " - Plus" if followed by + and " - Minus" if followed by -.)
//
//       (If letter grades are longer than 2 characters, the rest are ignored;
//       if the letter grade is followed by anything but + or -, that also
//       is ignored.)
//
//   tests:
//       describeLetterGrade("A+") == "Outstanding achievement - Plus"
//       describeLetterGrade("a") == "Outstanding achievement"
//       describeLetterGrade("B") == "Commendable achievement"
//       describeLetterGrade("b-") == "Commendable achievement - Minus"
//       describeLetterGrade("c") == "Alright achievement"
//       describeLetterGrade("C-") == "Alright achievement - Minus"
//       describeLetterGrade("d") == "Below-Average achievement"
//       describeLetterGrade("D+") == "Below-Average achievement - Plus"
//       describeLetterGrade("G") == "Try again"
//       describeLetterGrade("H+") == "Try again - Plus"
//       describeLetterGrade("What?") == "Try again"
//       describeLetterGrade("Awwww!") == "Outstanding achievement"
//       describeLetterGrade("B+C") == "Commendable achievement - Plus"

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string describeLetterGrade(string letterGrade) {
    string gradeDescription = "";

    // Build beginning of description based on first char in
    // given letter grade. This is an example of the syntax
    // used for the C++ switch statement.  Note that the
    // switch statement is from the older C language and is
    // is limited to basic data types like char and int --
    // you can't use a switch statement on a string!
    // Remember, the "at" method on a string returns a char

    switch (letterGrade.at(0)) {
        case 'a':
        case 'A':
            gradeDescription = "Outstanding achievement";
            break;

        case 'b':
        case 'B':
            gradeDescription = "Commendable achievement";
            break;

        case 'c':
        case 'C':
            gradeDescription = "Alright achievement";
            break;

        case 'd':
        case 'D':
            gradeDescription = "Below-Average achievement";
            break;

        default:
            gradeDescription = "Try again";
    }

    // This adds on additional ending *if* letter grade includes
    // + or -
    // Note the need to check whether the string has more than
    // one character - if it doesn't, then .at(1) would throw
    // an error and stop execution

    if (letterGrade.length() > 1) {
        if (letterGrade.at(1) == '+') {
            gradeDescription += " - Plus";
        }
        else if (letterGrade.at(1) == '-') {
            gradeDescription += " - Minus";
        }
        // else append nothing - no need to write code for that!
    }

    return gradeDescription;
}

// signature: describeGrade: string -> string
// purpose: prompts the user to enter a series of grades, one at a time, and each time,
// a description will be given to those grades.

void describeGrade()
{

    for(int i = 0; i < 5; i++)
    {
        string userInput;
        cout << "Enter a letter grade, including + or -: " << endl;
        getline(cin, userInput);
        cout << "Grade description: ";
        cout << describeLetterGrade(userInput) << endl;
    }
}
