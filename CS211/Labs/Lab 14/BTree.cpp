// CS 211 Fall 2025 - Week 14 Lab
// Kai Frimodig & Matthew Anderson

#include <cstdlib>
#include <iostream>
#include <string>
#include "BTree.h"

using namespace std;

//--------------------------------------------
// Function: insertKey(T newKey)
// Purpose: insert newValue into the BTree
// Returns: true if successful insert
//--------------------------------------------

bool BTree::insertKey(T newKey) {
    if (root == NULL)
    {
        root = new BTreeNode;
        root->setKey(0, newKey);
        root->setLeaf(true);
        root->incKeyTally();
    }

    return insertKeyRecursive(newKey, root);
}

bool BTree::insertKeyRecursive(T newKey, BTreeNode *currPtr) {
    int currTallyOfKeys = currPtr->getKeyTally();

        if (currPtr->isLeaf())
        {
            if (currTallyOfKeys == M - 1)
            {
                return splitNode(currPtr);
            }

            for (int j = 0; j < currTallyOfKeys; j++)
            {
                if (newKey < currPtr->getKey(j))
                {
                    for (int k = currTallyOfKeys; k > 0; k--)
                    {
                        currPtr->setKey(k, currPtr->getKey(k - 1));
                    }

                    currPtr->setKey(j, newKey);
                    cout << currPtr->getKey(j) << endl;
                    return true;
                }
            }
        }
        else
        {
            for (int i = 0; i < currTallyOfKeys; i++)
            {
                cout << "got here" << endl;
                return insertKeyRecursive(newKey, currPtr->getPointer(i));
            }
        }
}

//--------------------------------------------
// Function: deleteKey(T oldKey)
// Purpose: delete oldValue from the BTree
// Returns: true if successful delete
//--------------------------------------------

bool BTree::deleteKey(T oldKey) {
    return false;  // REPLACE THIS LINE
}

bool BTree::deleteKeyRecursive(T oldKey, BTreeNode *currPtr) {
    return false;  // REPLACE THIS LINE
}

//--------------------------------------------
// Function: printBTree()
// Purpose: prints the contents of the BTree
//          using an inorder traversal
// Returns: nothing
//--------------------------------------------

void BTree::printBTree() const {
    // Navigate the BTree in inorder to print the sorted key values
    // This is done RECURSIVELY using BTreeNode instances
    this->printBTreeRecursive(this->getRoot());
    cout << endl;
}

//--------------------------------------------
// Function: printBTreeRecursive(BTreeNode*)
// Purpose: prints the values in the current node
//          and each of its children nodes
// Returns: nothing
//--------------------------------------------

void BTree::printBTreeRecursive(BTreeNode *currPtr) const {
    BTreeNode *childPtr;

    // If the currPtr is null, then no node here, so return right away
    if (currPtr == NULL) return;

    cout << " : ";
    // Print the values of the current BTreeNode, visiting the children as well
    int currNodeKeyTally = currPtr->getKeyTally();

    for (int currIndex=0; currIndex<=currNodeKeyTally; currIndex++) {

        // Recursively call this method to visit the child Node
        // (if it exists) before the key value at index currIndex

        printBTreeRecursive(currPtr->getPointer(currIndex));

        // Print key at current index value, if there are still keys
        // to be printed.  Get out of for loop when there are no more.

        if (currIndex < currNodeKeyTally)
            cout << currPtr->getKey(currIndex) << " ";
        else
            break;
    }
    // The : is useful to see when we go from one node to another
    cout << " : ";

    // We're done with this node!
    return;
}
