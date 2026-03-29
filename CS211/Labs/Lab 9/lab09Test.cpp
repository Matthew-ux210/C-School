// CS 211 Fall 2025 - Week 09 Lab
// ArrayQueue class

//---------------------------------------------------------------
// File: testQueue.cpp
// Purpose: Main file with tests for a demonstration of a queue.
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "ArrayQueue.h"

using namespace std;

int main() {
    cout << boolalpha;

    // "el" is short for "element"
    int el;

    cout << "Simple Queue Demonstration -- Creating a queue\n";

    ArrayQueue myQueue; // Create a queue object

    cout << "Queue created...\n";

    cout << "(Should be true) ";
    cout << "Is the queue empty to start? " << myQueue.isEmpty() << endl;
    cout << "(Should be false) ";
    cout << "Is the queue full to start? " << myQueue.isFull() << endl;

    for (int i=1; i<10; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i << " to queue: " << myQueue.enQueue(i) << endl;
    }

    cout << "(Should be 1) Element at front is " << myQueue.frontEl() << endl;

    cout << "(Should be false) ";
    cout << "Is the queue full? " << myQueue.isFull() << endl;

    cout << "(Should be true) ";
    cout << "Adding 10 to queue: " << myQueue.enQueue(10) << endl;

    cout << "(Should be true) ";
    cout << "Is the queue full? " << myQueue.isFull() << endl;

    myQueue.printQueue();

    cout << "(Should be false) ";
    cout << "Trying to add 11 to queue: " << myQueue.enQueue(11) << endl;

    cout << "(Should be true) ";
    cout << "Is the queue full? " << myQueue.isFull() << endl;

    cout << "(Should be false) ";
    cout << "Is the queue empty? " << myQueue.isEmpty() << endl;

    for (int i=1; i<10; i++) {
        cout << "Element at front is " << myQueue.frontEl() << endl;
        cout << "Removing " << myQueue.deQueue() << " from queue " << endl;
    }

    cout << "(Should be false) ";
    cout << "Is the queue full? " << myQueue.isFull() << endl;

    cout << "(Should be false) ";
    cout << "Is the queue empty? " << myQueue.isEmpty() << endl;

    cout << "Element at front is " << myQueue.frontEl() << endl;

    myQueue.printQueue();

    cout << "Removing " << myQueue.deQueue() << " from queue " << endl;

    cout << "(Should be false) ";
    cout << "Is the queue full? " << myQueue.isFull() << endl;

    cout << "(Should be true) ";
    cout << "Is the queue empty? " << myQueue.isEmpty() << endl;

    for (int i=1; i<10; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i*100 << " to queue: "
             << myQueue.enQueue(i*100) << endl;
    }

    myQueue.printQueue();

    for (int i=1; i<7; i++) {
        cout << "Removing " << myQueue.deQueue() << " from queue " << endl;
    }

    cout << "Element at front is " << myQueue.frontEl() << endl;

    myQueue.printQueue();

    for (int i=10; i<12; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i*1000 << " to queue: "
        << myQueue.enQueue(i*1000) << endl;
    }

    myQueue.printQueue();

    while (! myQueue.isEmpty()) {
        cout << "Element at front is " << myQueue.frontEl() << endl;
        cout << "Removing " << myQueue.deQueue() << " from queue " << endl;
    }

    cout << "(Should be true) ";
    cout << "Is the queue empty? " << myQueue.isEmpty() << endl;

    myQueue.printQueue();

    for (int i=12; i<17; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i*10 << " to queue: " << myQueue.enQueue(i*10)
             << endl;
    }

    cout << "Element at front is " << myQueue.frontEl() << endl;

    myQueue.printQueue();

    cout << "Clearing queue " << endl;
    myQueue.clearQueue();
    cout << endl;

    cout << "(Should be true) ";
    cout << "Is the queue empty? " << myQueue.isEmpty() << endl;

    return EXIT_SUCCESS;
}
