// CS 211 Fall 2025 - Week 08 Lab
// Kai Frimodig and Matt Anderson

//---------------------------------------------------------------
// File: ArrayStack.cpp
// Purpose: Implementation file for a demonstration of a stack
//          implemented as an array.    Data type: Double
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include "ArrayStack.h"

//--------------------------------------------
// Function: ArrayStack()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

ArrayStack::ArrayStack() {
    // top is the index of the array where the top
    // of the stack is; a value of -1 means the
    // stack is empty
    top = -1;
    currCapacity = CAPACITY;
    theStack = new T[CAPACITY];
}

//--------------------------------------------
// Function: clearStack()
// Purpose: Remove all items from the stack
// Returns: void
//--------------------------------------------

void ArrayStack::clearStack() {
    top = -1; // Reset count to start over
              // NOTE: There's no need to reset
              // array values!  Just reset index

    currCapacity = CAPACITY;
    T* newStack = new T[currCapacity];
    delete[] theStack;
    theStack = newStack;
}

//--------------------------------------------
// Function: push()
// Purpose: Push an item onto the stack.
// Returns: true if push was successful
//          or false if the push failed.
//--------------------------------------------

bool ArrayStack::push(T el)
{
    // Check to see if the stack if full
    if (top >= (currCapacity - 1))
    {
        currCapacity += CAPACITY;
        T* newStack = new T[currCapacity];

        for (int i = 0; i < top + 1; ++i)
        {
            newStack[i] = theStack[i];
        }

        delete[] theStack;
        theStack = newStack;
    }

    // Increment array index of top of stack
    top++;
    // Add the item to the stack
    theStack[top] = el;

    return true;
}

//--------------------------------------------
// Function: pop()
// Purpose: Pop an item from the Stack.
// Returns: value of item popped if pop was successful
//  or -99999.0 if the pop failed (stack empty)
//--------------------------------------------

T ArrayStack::pop() {
    T el;

    // Check for empty stack
    if (isEmpty()) return ERROR_VALUE;
    else {
        el = theStack[top]; // Get value to return
        top--;     // Decrement top index
        return el; // Return popped value
    }
}

bool ArrayStack::changeCurrCapacity(int newCapacity)
{
    if (newCapacity >= currCapacity)
    {
        T* newStack = new T[newCapacity];
        for (int i = 0; i < currCapacity; ++i)
        {
            newStack[i] = theStack[i];
        }

        delete[] theStack;
        currCapacity = newCapacity;
        theStack = newStack;

        return true;
    }
    else
    {
        return false;
    }
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the stack is empty
// Returns: true if empty, otherwise false
//--------------------------------------------

bool ArrayStack::isEmpty() {
    // top value is -1 if the stack is empty
    return (top == -1);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the stack is full
// Returns: true if full, otherwise false
//--------------------------------------------

bool ArrayStack::isFull() {
    return false;
}
