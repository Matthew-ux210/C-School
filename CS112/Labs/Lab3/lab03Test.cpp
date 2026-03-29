// CS 112 Spring 2025 - Week 03 Lab
// Overloading and Call by Reference
// Do NOT submit this file to Canvas!

#include <cstdlib>
#include <iostream>
#include <string>
#include "lab03.h"

using namespace std;

int main() {
    cout << boolalpha;

    int    intVal = 7;
    double doubleVal = 13.4;
    bool   boolVal = false;
    string stringVal = "Fred";

    cout << "*** Testing displayCallByValue using CALL BY VALUE ***" << endl
         << "*** Memory addresses for arguments and parameters  ***" << endl
         << "*** should be DIFFERENT                            ***" << endl
         << endl;

    // *** UNCOMMENT LINES BELOW when you're ready to run your tests

    cout << "In main(), intVal has value " << intVal
         << " at memory address " << &intVal << endl;
    displayCallByValue(intVal);



    cout << "In main(), doubleVal has value " << doubleVal
         << " at memory address " << &doubleVal << endl;
    displayCallByValue(doubleVal);

    cout << "In main(), boolVal has value " << boolVal
         << " at memory address " << &boolVal << endl;
    displayCallByValue(boolVal);

    cout << "In main(), stringVal has value " << stringVal
         << " at memory address " << &stringVal << endl;
    displayCallByValue(stringVal);

    cout << endl;

    cout << "*** Testing displayCallByRef using CALL BY REFERENCE ***" << endl
         << "*** Memory addresses for arguments and parameters    ***" << endl
         << "*** should be THE SAME                               ***" << endl
         << endl;

    cout << "In main(), intVal has value " << intVal
         << " at memory address " << &intVal << endl;
    displayCallByRef(intVal);

    cout << "In main(), doubleVal has value " << doubleVal
         << " at memory address " << &doubleVal << endl;
    displayCallByRef(doubleVal);

    cout << "In main(), boolVal has value " << boolVal
         << " at memory address " << &boolVal << endl;
    displayCallByRef(boolVal);

    cout << "In main(), stringVal has value " << stringVal
         << " at memory address " << &stringVal << endl;
    displayCallByRef(stringVal);

    cout << endl;

    // ****************************************************************

    cout << "*** Testing getEmployeeInfo ***" << endl;

    string empName = "NoName";
    int empAge = 0;
    double empSalary = 0.0;
    bool empExempt = false;

    // *** UNCOMMENT LINE BELOW when you're ready to run your tests

    getEmployeeInfo(empName, empAge, empSalary, empExempt);

    // print out the employee info gathered in getEmployeeInfo

    cout << "*** Employee info entered in getEmployeeInfo *** " << endl
         << "Name:   " << empName << endl
         << "Age:    " << empAge << endl
         << "Salary: " << empSalary << endl
         << "Exempt: " << empExempt << endl;

    return EXIT_SUCCESS;
}
