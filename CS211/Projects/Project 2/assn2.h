// CS 211 Fall 2025 - Assignment 02 Test File
// Matthew Anderson

#ifndef ASSN2_H
#define ASSN2_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// PROBLEM 1

void addCommas(unsigned long long int);

// PROBLEM 2

//---------------------------------------------------------------
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------
//--------------------------------------------------
//  class: DLLNode
//
//  purpose: To create a data element for a Doubly Linked List
//
//  NOTE: ALL CODE FOR DLLNode IS IN THIS FILE AND MUST *NOT*
//        BE ALTERED IN ANY WAY!
//--------------------------------------------------

class DLLNode {
  public:
    DLLNode();
    DLLNode(const double el, DLLNode *nPtr = NULL, DLLNode *pPtr = NULL) {
        info = el;         // Place value into new node
        nextPtr = nPtr;    // Set link to next node in list
        prevPtr = pPtr;    // Set link to previous node in list
    };

    // To make things easier and avoid having to write accessors and
    // mutators, we'll just be lazy and make everything public :-)

    double info;
    DLLNode *nextPtr, *prevPtr;
};

class DoublyLinkedList {
  public:
    DoublyLinkedList();           // Class constructor
    void addToDLLTail(double el); // Add a DLLNode with value el to tail of DLL
    double deleteFromDLLTail();   // Remove a DLLNode from tail, return value
    void addToDLLHead(double el);
    double deleteFromDLLHead();

  private:
    DLLNode *headPtr;
    DLLNode *tailPtr;
};

#endif /* ASSN2_H */
