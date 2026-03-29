// CS 112 Spring 2025 - Week 03 Lab
// Matthew Anderson, Jesse Perez, Jonah Gothe

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// See the H file for the headers of the functions
// to be written here

// *******************************
// *** CALL BY VALUE FUNCTIONS ***
// *******************************

// displayCallByValue: value -> void
//    (value can be int, double, bool, or string)
// Expects a value of one of the listed types
//    and returns nothing
// Side effect: prints to the screen the value
//    passed to the function and the memory
//    address where that value is stored

void displayCallByValue(int intVal)
{
    cout << "Parameter has the value " << intVal
         << " at memory address " << &intVal << endl;
}

void displayCallByValue(double doubleVal)
{
    cout << "Parameter has the value " << doubleVal
         << " at memory address " << &doubleVal << endl;
}

void displayCallByValue(bool boolVal)
{
    cout << "Parameter has the value " << boolVal
        << " at memory address " << &boolVal << endl;
}

void displayCallByValue(string stringVal)
{
     cout << "Parameter has the value " << stringVal
         << " at memory address " << &stringVal << endl;

}


// ***********************************
// *** CALL BY REFERENCE FUNCTIONS ***
// ***********************************

// displayCallByRef: value -> void
//    (value can be int, double, bool, or string)
// Expects a value of one of the listed types
//    and returns nothing
// Side effect: prints to the screen the value
//    passed to the function and the memory
//    address where that value is stored

void displayCallByRef(int& intVal)
{
    cout << "Parameter has the value " << intVal
         << " at memory address " << &intVal << endl;
}

void displayCallByRef(double& doubleVal)
{
    cout << "Parameter has the value " << doubleVal
         << " at memory address " << &doubleVal << endl;
}

void displayCallByRef(bool& boolVal)
{
    cout << "Parameter has the value " << boolVal
        << " at memory address " << &boolVal << endl;
}

void displayCallByRef(string& stringVal)
{
    cout << "Parameter has the value " << stringVal
         << " at memory address " << &stringVal << endl;
}

// getEmployeeInfo: string& int& double& bool& -> void
// Expects parameters for an employee's last name, age, salary, and
//    overtime-exempt status PASSED BY REFERENCE
// Returns nothing
// Side effect: prompts the user to enter the employee information
//    and stores the values in the parameter variables
// NOTE: Use cin for all data entry, not getline

void getEmployeeInfo(string& empName, int& empAge, double& empSalary, bool& empExempt)
{

    char ifExem;

    cout << "Enter Employee's Name: ";
    cin >> empName;

    cout << "Enter Employee's Age: ";
    cin >> empAge;

    cout << "Enter Employee's Monthly Salary: ";
    cin >> empSalary;

    cout << "Is the Employee Exempt? (Type y or n): ";
    cin >> ifExem;

    if (ifExem == 'y')
        empExempt = true;
    else if (ifExem == 'n')
        empExempt = false;
    else
        cout << "Virus Time!" << endl;
}



