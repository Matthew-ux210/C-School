// CS 211 Fall 2025 - Week 13 Lab
// C++ MinHeap class

#include <cstdlib>
#include <iostream>
#include <string>
#include "MinHeap.h"

using namespace std;

int main() {

    cout << boolalpha;

    // First test:  *** AUTO-TEST ***
    cout << "*** AUTO-TEST: ";

    MinHeap xHeap;
    bool autotest = true;
    T testVals[15] = {85, 60, 25, 10, 35, 70, 15, 30,
                      20, 45, 80, 75, 55, 50, 40};
    T sortVals[15] = {10, 15, 20, 25, 30, 35, 40, 45,
                      50, 55, 60, 70, 75, 80, 85};
    for (int i=0; i<15; i++)
        xHeap.insertValue(testVals[i]);
    for (int j=0; j<15; j++)
        if (xHeap.removeValue() != sortVals[j])
            autotest = false;
    cout << autotest << " ***" << endl;

    MinHeap *testHeap;
    int size;
    T newValue;
    char response;

    cout << "*** INTERACTIVE TEST ***" << endl;
    cout << "Size of heap?  Enter 0 for default size: ";
    cin >> size;

    if (size <= 0)
        testHeap = new MinHeap();
    else
        testHeap = new MinHeap(size);

    cout << "*** TESTS OF MINHEAP ***" << endl;
    cout << "Enter a value into the heap (99999 to end): ";
    cin >> newValue;

    while (newValue != 99999) {
        testHeap->insertValue(newValue);
        testHeap->display();

        cout << "Enter next value (99999 to end): ";
        cin >> newValue;
    }

    testHeap->display();

    cout << "Do you want to remove a value (y/n)? ";
    cin >> response;

    while (response == 'y' || response == 'Y') {
        cout << "Value " << testHeap->removeValue()
             << " removed from the heap!" << endl;
        testHeap->display();

        cout << "Remove another value (y/n)? ";
        cin >> response;
    }

    testHeap->display();
    cout << "All done!" << endl;
    delete testHeap;

    return EXIT_SUCCESS;
}

