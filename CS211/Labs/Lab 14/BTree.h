//  CS 211 Fall 2025 - Week 14 Lab
//  B-Trees in C++ - DO NOT SUBMIT THIS FILE!

#ifndef BTREE_H
#define BTREE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

// We'll set a typedef statement here
// The type T represents the data type stored in the hash table
// For the data type stored in the hash table buckets,
// it'd be great if you used T instead of int in your code :-)

typedef int T;     // Data type for each key value in a BTreeNode

const int M = 5;   // Set BTree to degree = 5
const int DEFAULTKEYVAL = -99999; // Value for an "empty" key

// Placing all BTreeNode code in the .H file for the BTree
// class -- "quick 'n' sleazy"

class BTreeNode {
public:

    // One constructor:
    //    BTreeNode() creates an "empty" B-Tree node
    BTreeNode() {
        leaf = true;
        keyTally = 0;
        for (int i=0; i<M; i++) {
            pointers[i] = NULL;
            if (i<M-1)
                keys[i] = DEFAULTKEYVAL;
        }
    }

    // Destructor
    ~BTreeNode() { }

    // Accessors
    bool isLeaf() const { return leaf; }
    int getKeyTally() const { return keyTally; }
    T getKey(int index) { return keys[index]; }
    BTreeNode *getPointer(int index) { return pointers[index]; }

    // Mutators
    void setLeaf(bool leafVal) { leaf = leafVal; }
    void incKeyTally() { keyTally++; }
    void decKeyTally() { keyTally--; }
    void setKey(int index, T newVal)
        { keys[index] = newVal; }
    void setPointer(int index, BTreeNode *newPtr)
        { pointers[index] = newPtr; }

private:
    bool leaf;      // Set to true if the BTreeNode is a leaf
    int keyTally;   // The number of key values stored in the BTreeNode
    T keys[M-1];    // Key values stored in the BTreeNode
    BTreeNode *pointers[M];  // Child pointers in the BTreeNode
};


/*-----
  class: BTree

  purpose: To implement a BTree containing int values

  Methods:
        *   BTree initializes the root pointer to NULL
        *   setRoot points the root pointer to a BTreeNode
        *   printBTree prints the key values in order
        *   splitNode (NOT IMPLEMENTED) splits a Node into two
        *   mergeNode (NOT IMPLEMENTED) merges two Nodes into one
        *   insertKey inserts a value into a BTreeNode
        *   deleteKey removes a value from a BTreeNode
-----*/

class BTree {
public:

    // One constructor:
    //    BTree() creates an "empty" BTree

    BTree() { root = NULL; }

    // Destructor
    ~BTree();

    // Accessors
    BTreeNode *getRoot() const { return root; }
    void printBTree() const;

    // Mutators
    void setRoot(BTreeNode *newRoot) { root = newRoot; }

    // In place of a true splitNode method
    bool splitNode(BTreeNode *currNode) {
        cout << endl;
        cout << "*** splitNode METHOD CALLED! ***" << endl;
        cout << endl;
        return false;
    }

    // In place of a true mergeNode method
    bool mergeNodes() {
        cout << endl;
        cout << "*** mergeNodes METHOD CALLED! ***" << endl;
        cout << endl;
        return false;
    }

    // HERE ARE THE METHODS TO BE WRITTEN FOR THIS LAB
    bool insertKey(T newKey);
    bool deleteKey(T oldKey);

private:
    void printBTreeRecursive(BTreeNode *currPtr) const;
    bool insertKeyRecursive(T newKey, BTreeNode *currPtr);
    bool deleteKeyRecursive(T oldKey, BTreeNode *currPtr);

    BTreeNode *root;
};

#endif /* BTREE_H */

