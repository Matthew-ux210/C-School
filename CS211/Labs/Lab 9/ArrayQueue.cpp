// CS 211 Fall 2025 - Week 09 Lab
// Matthew Anderson and Trevor Troy

//---------------------------------------------------------------
// File: ArrayQueue.cpp
// Purpose: Implementation file for a queue
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "ArrayQueue.h"

using namespace std;

// Private function nextIndex correctly calculates the next
// index value within the array
void nextIndex(int& currIndex) {
    currIndex = (currIndex + 1 + QUEUE_SIZE) % QUEUE_SIZE;
}

//--------------------------------------------
// CONSTRUCTORS
//--------------------------------------------

ArrayQueue::ArrayQueue() {
    queueArray = new T[QUEUE_SIZE];
    frontIndex = 0;
    backIndex = 0;
    queueEmpty = true;
}

ArrayQueue::~ArrayQueue() {
    delete [] queueArray;
}

//--------------------------------------------
// isFull: void -> bool
// Purpose: Returns true is queue is full
// Side Effects: None
//--------------------------------------------

bool ArrayQueue::isFull() {
    int difference = (backIndex - frontIndex) + QUEUE_SIZE;
    return (difference % QUEUE_SIZE == QUEUE_SIZE - 1);
}

//--------------------------------------------
// isEmpty: void -> bool
// Purpose: Returns true if queue is empty
// Side Effects: None
//--------------------------------------------

bool ArrayQueue::isEmpty() {
    return queueEmpty;
}

//--------------------------------------------
// firstEl: void -> T
// Purpose: Returns element at head of queue
// Side Effects: None
//--------------------------------------------

T ArrayQueue::frontEl() {
    if(queueEmpty)
        return -9999;
    return queueArray[frontIndex];
}

//--------------------------------------------
// clearQueue: void -> void
// Purpose: Removes all items from the queue
// Side Effects: resets queue to empty
//--------------------------------------------

void ArrayQueue::clearQueue() {
    queueEmpty == true;
    frontIndex == backIndex;
}

//--------------------------------------------
// enQueue: T -> bool
// Purpose: Returns true if element successfully added
// Side Effects: Adds element to queue
//--------------------------------------------

bool ArrayQueue::enQueue(T el) {
    if(this->isFull()){
        return false;
    }
    if(this->isEmpty()){
        queueEmpty = false;
        queueArray[backIndex] = el;
        return true;
    }
    nextIndex(backIndex);
    queueArray[backIndex] = el;
    return true;
}

//--------------------------------------------
// deQueue: void -> T
// Purpose: Returns element at front of queue
// Side Effects: Removes element from queue
//--------------------------------------------

T ArrayQueue::deQueue() {
    T tempVal;

    if(queueEmpty)
        return -9999;

    if(frontIndex == backIndex){
        queueEmpty == true;
        return queueArray[frontIndex];
    }
        tempVal = queueArray[frontIndex];
        nextIndex(frontIndex);
        return tempVal;
    }

//--------------------------------------------
// printQueue: void -> void
// Purpose: prints contents of the queue
//--------------------------------------------

void ArrayQueue::printQueue() {
    cout << "*** Contents of queue ***" << endl;
    cout << "Front at array index " << frontIndex
         << ", Back at array index " << backIndex << endl;

    if (isEmpty()) {
        cout << "*** Queue is empty ***" << endl;
        return;
    }

    cout << "QUEUE IS: ";
    int currIndex = frontIndex;
    while (currIndex != backIndex) {
        cout << queueArray[currIndex] << " ";
        nextIndex(currIndex);
    }
    cout << queueArray[backIndex] << endl;

    cout << "ARRAY CONTAINS: ";
    for (int i=0; i<QUEUE_SIZE; i++)
        cout << queueArray[i] << " ";
    cout << endl << "*************************" << endl;
}

