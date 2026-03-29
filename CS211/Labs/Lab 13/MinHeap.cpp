// CS 211 Fall 2025 - Week 13 Lab
// Matthew Anderson & Reece Dickinson

//----------------------------------------------------
// File: MinHeap.cpp
// Purpose: Implementation file for a MinHeap class
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "MinHeap.h"

using namespace std;

// Helper function to swap values

void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

// Constructors

MinHeap::MinHeap() {
    heapCapacity = DEFAULT_CAPACITY;
    heapArray = new T[heapCapacity];
}

MinHeap::MinHeap(int capacity) {
    heapCapacity = capacity;
    heapArray = new T[heapCapacity];
}

MinHeap::~MinHeap() {
    delete [] heapArray;
}

//--------------------------------------------
// Method: getSize()
// Purpose: accessor for size of MinHeap
// Returns: current number of values in the MinHeap
//--------------------------------------------

int MinHeap::getSize() const {
    return heapSize;
}

//--------------------------------------------
// Method: getCapacity()
// Purpose: accessor for capacity of MinHeap
// Returns: total capacity of MinHeap
//--------------------------------------------

int MinHeap::getCapacity() const {
    return heapCapacity;
}

//--------------------------------------------
// Method: display()
// Purpose: prints size, capacity, and values
// stored in MinHeap array (up to its size)
// Returns: nothing
//--------------------------------------------

void MinHeap::display() const {
    cout << "*** Heap displayed here!\n"; // DELETE THIS LINE
    for(int i = 0; i < heapSize; i++){
        cout << heapArray[i] << " ";
    }
    cout << endl;
}

//--------------------------------------------
// Method: insertValue(T)
// Purpose: inserts new value into MinHeap
// Returns: true if insert is successful
//--------------------------------------------

bool MinHeap::insertValue(T newValue) {
    if(heapSize >= heapCapacity)
        return false;

    heapSize++;
    if(heapSize == 1) {
        heapArray[0] = newValue;
        return true;
        }

    int k = heapSize-1;
    heapArray[k] = newValue;
    while(k != 0){
        if (heapArray[k] < heapArray[(k-1)/2])
            swap(heapArray[k], heapArray[(k-1)/2]);
            k = (k-1)/2;
    }
    return true;
}

//--------------------------------------------
// Function: removeValue()
// Purpose: inserts value from MinHeap
// Returns: true if removal is successful
//--------------------------------------------

T MinHeap::removeValue() {
    if(heapSize == 0)
        return -99999;

    T temp = heapArray[0];
    swap(heapArray[0], heapArray[heapSize-1]);
    heapSize--;

    int i = 0;
    while(true){
        int leftChild = heapArray[2*i + 1];
        int rightChild = heapArray[2*i + 2];
        int smallest = i;

        if(leftChild < heapSize && heapArray[leftChild] < heapArray[smallest])
                smallest = leftChild;
        if(rightChild < heapSize && heapArray[rightChild] < heapArray[smallest])
                smallest = rightChild;

        if(smallest == i)
            break;

        swap(heapArray[i], heapArray[smallest]);
        i = smallest;
    }
    return temp;
}
