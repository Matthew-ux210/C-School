// CS 211 Fall 2025 - Assignment 03
// <INSERT YOUR NAME HERE>

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Set data type of node contents
typedef int T;


//   class: BSTNode
//
//   purpose: To create a BSTNode for use in a BST
//   NOTE: All code for the class is in this .h file
//   Do NOT alter this class's code in any way!
//   by: David Tuttle
//   last modified: 13 Oct 2025

class BSTNode {
public:
    // Two constructors:
    //    BSTNode() creates an "empty" node with no value for el
    //    BSTNode() crates a node with the given el value and
    //              (optionally) two pointers to "children"
    BSTNode(): leftChildPtr(NULL), rightChildPtr(NULL) {}

    BSTNode(T e, BSTNode *lPtr = NULL, BSTNode *rPtr = NULL)
           { el = e; leftChildPtr = lPtr; rightChildPtr = rPtr; }

    // Accessors
    T getEl()                   { return el; }
    BSTNode *getLeftChildPtr()  { return leftChildPtr; }
    BSTNode *getRightChildPtr() { return rightChildPtr; }

    // Mutators
    void setEl(T newEl)                  { el = newEl; }
    void setLeftChildPtr(BSTNode *lPtr)  { leftChildPtr = lPtr; }
    void setRightChildPtr(BSTNode *rPtr) { rightChildPtr = rPtr; }

private:
    T el;
    BSTNode *leftChildPtr;
    BSTNode *rightChildPtr;
};


//   class: BST
//
//   purpose: To implement a binary search tree
//            using the given BSTNode class
//     *   Constructor BST() sets root pointer to NULL
//     *   isEmpty returns TRUE if the tree is empty
//     *   search returns TRUE if value is found in the tree
//     *   breadthFirstTraversal prints out the node values
//     *   insert places a node into the tree

class BST {
public:
    // Constructor
    BST(): rootPtr(NULL) {}

    // Accessor
    BSTNode* getRootPtr() { return rootPtr; }

    // Methods
    bool isEmpty() const;
    bool search(T el) const;
    void breadthFirstTraversal() const;
    bool insert(T el);

    // *****************************************************
    // METHODS TO BE WRITTEN
    // *****************************************************

    void preorderTraversal() const;
    void inorderTraversal() const;
    void postorderTraversal() const;

    int countNodes() const;
    int countLeafs() const;
    int countInterior() const;
    int treeHeight() const;

    bool deleteNode(T el);
    bool leftRotation(BSTNode& gp, BSTNode& par, BSTNode& ch);
    bool rightRotation(BSTNode& gp, BSTNode& par, BSTNode& ch);

private:
    BSTNode *rootPtr;

};

#endif /* BST_H */

