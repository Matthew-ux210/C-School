// CS 211 Fall 2025 - Assignment 02 Test File
// Matthew Anderson

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include "assn2.h"

// PROBLEM 1

void addCommas(unsigned long long int theNumber) {
    if(theNumber < 1000){
        cout << theNumber;
        return;
    }

    unsigned long long int hPart = theNumber / 1000;
    unsigned long long int lPart = theNumber % 1000;

    addCommas(hPart);

    cout << "," << setfill('0') << setw(3) << lPart;
}

// PROBLEM 2

//---------------------------------------------------------------
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

// CONSTRUCTOR(S)

DoublyLinkedList::DoublyLinkedList() {
  headPtr = NULL;
  tailPtr = NULL;
}

// OTHER METHODS


void DoublyLinkedList::addToDLLTail(double el) {
    if (tailPtr != NULL) {                      // If DLL is non-empty
          tailPtr = new DLLNode(el,0,tailPtr);  // Allocate new DLLNode
          tailPtr->prevPtr->nextPtr = tailPtr;  // Link new node to tail of DLL
    }
    else {                                // If DLL is empty
        headPtr = new DLLNode(el);        // Allocate new DLLNode
        tailPtr = headPtr;                // Node is first in the DLL, so it
                                          // is both head and tail
    }
}


double DoublyLinkedList::deleteFromDLLTail() {
    double el = tailPtr->info;            // Get value of node to be deleted

    if (tailPtr == NULL)
        throw("EMPTY");                   // Return an error condition

    else if (headPtr == tailPtr) {        // If only DLLNode in the DLL
        delete headPtr;                   // Deallocate DLLNode
        headPtr = NULL;                   // Set both head and tail to values for
        tailPtr = NULL;                   // a DLL with no nodes
    }

    else {                                // If more than one DLLNode in DLL
        tailPtr = tailPtr->prevPtr;       // Move tail to previous DLLNode
        delete tailPtr->nextPtr;          // Deallocate DLLNode
        tailPtr->nextPtr = NULL;          // Set next of new last DLLNode to NULL
    }
    return el;                            // Return value in deleted DLLNode
}

void DoublyLinkedList::addToDLLHead(double el){
   if(headPtr != NULL){
    headPtr = new DLLNode(el,headPtr,0);
    headPtr->nextPtr->prevPtr = headPtr;
   }
   else{
    headPtr = new DLLNode(el);
    tailPtr = headPtr;
   }
}

double DoublyLinkedList::deleteFromDLLHead(){
    if(headPtr==NULL);
        throw("EMPTY");

    double el = headPtr->info;

    if (headPtr == tailPtr) {
        delete headPtr;
        headPtr = NULL;
        tailPtr = NULL;
    }

    else {
    headPtr = headPtr->nextPtr;
    delete headPtr->prevPtr;
    headPtr->prevPtr = NULL;
}

    return el;

}
