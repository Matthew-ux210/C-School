// CS 211 Fall 2025 - Week 08 Lab
// Kai Frimodig and Matt Anderson

//---------------------------------------------------------------
// File: week08Lab.cpp
// Purpose: Main file with tests for a demonstration of an unsorted
//          stack implemented as an array.
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include "ArrayStack.h"

using namespace std;

int main() {
    cout << boolalpha;

    // generic variable to hold an index value as needed
    int i;
    // "el" is short for "element" - a place to store pushed or popped value
    T el;

    cout << "Simple Stack Demonstration\n";
    cout << "(Stack implemented as Array - Element data type is double.)\n\n";
    cout << "Creating a stack\n";

    ArrayStack *theStack = new ArrayStack(); // Create a stack object

    cout << "Stack created...\n";

    cout << "Testing changeCurrCapacity(), should return true if the capacity was successfully changed" << endl;
    cout << theStack->changeCurrCapacity(13) << endl;

    cout << "Testing changeCurrCapacity(), should return false if the capacity was unsuccessfully changed" << endl;
    cout << theStack->changeCurrCapacity(4) << endl;

    cout << endl;

    // Test pushing and popping a single item on the stack

    el = 100.0;
    cout << "Testing push and pop of single item.\n";
    cout << "Pushing a single double value of " << el << "\n";
    theStack->push(el);
    cout << "Popped: " << theStack->pop() << "\n";
    cout << "...done\n\n";

    // Let's try popping a value off an empty stack

    cout << "Testing pop of an empty stack.  Should print -99999\n";
    cout << "Popped: " << theStack->pop() << "\n";
    cout << "...done\n\n";

    // Test stack by reversing the order of numbers pushed onto stack
    cout << "Enter a list of numbers to be reversed (-1 to end):\n\n";

    // Push numbers on the stack
    i = 0;
    cout << "Enter the first number: ";
    cin >> el;
    while (el != -1 && i < CAPACITY) {
        theStack->push(el);
        i++;

        if (i == CAPACITY) {
	        cout << "Your stack is full!\n";
        }
        else {
            cout << "Enter the next number: ";
            cin >> el;
        }
    }

    // Pop letters and print in reverse
    cout << "Your numbers printed in reverse is...\n";
    while(theStack->isEmpty() == false) {
        el = theStack->pop();
        cout << el << " ";
    }



    cout << "\n\n...done.\n";

    return EXIT_SUCCESS;
}
