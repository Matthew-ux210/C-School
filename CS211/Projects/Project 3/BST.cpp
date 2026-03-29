// CS 211 Fall 2025 - Assignment 03
// <INSERT YOUR NAME HERE>

//----------------------------------------------------
// File: BST.cpp
// Purpose: Implementation file for a demonstration
// of a basic binary tree
//
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

//--------------------------------------------
// Function: isEmpty()
// Purpose: determine whether a BST has no nodes
// Returns: a boolean - true if empty
//--------------------------------------------

bool BST::isEmpty() const {
    return (rootPtr == NULL);
}

//--------------------------------------------
// Function: search(T)
// Purpose: search for a value in a binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::search(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *pPtr = rootPtr;
    T currVal;  // Current value of the BSTNode that p points to

    // Descend the tree to search for the given input value
    while (pPtr != NULL) {

        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = pPtr->getEl();
        if (el < currVal)
            pPtr = pPtr->getLeftChildPtr();
        else if (el > currVal)
            pPtr = pPtr->getRightChildPtr();
        else
            // Value found!  Return true
            return true;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding anything.  Return false
    return false;
}

//--------------------------------------------
// Function: breadthFirstTraversal()
// Purpose: Expects nothing, returns nothing
// Side Effects: prints values in breadth-first order
//--------------------------------------------

void BST::breadthFirstTraversal() const {
    const int QUEUE_SIZE = 50;
    BSTNode *queue[QUEUE_SIZE];
    int headIndex = 0;
    int tailIndex = 0;

    if (rootPtr == NULL) {
        cout << "*** Tree is empty ***" << endl;
        return;
    }

    queue[tailIndex] = rootPtr;

    while (headIndex != tailIndex + 1) {
        if (queue[headIndex]->getLeftChildPtr() != NULL) {
           tailIndex = (tailIndex + 1) % QUEUE_SIZE;
           queue[tailIndex] = queue[headIndex]->getLeftChildPtr();
        }
        if (queue[headIndex]->getRightChildPtr() != NULL) {
           tailIndex = (tailIndex + 1) % QUEUE_SIZE;
           queue[tailIndex] = queue[headIndex]->getRightChildPtr();
        }
        cout << queue[headIndex]->getEl() << " ";
        headIndex = (headIndex + 1) % QUEUE_SIZE;
    }
    cout << endl;
}

//--------------------------------------------
// Function: insert(T)
// Purpose: insert a BSTNode into the BST
// Returns: true is successful, false if not
//--------------------------------------------

bool BST::insert(T el) {
    // Pointers to keep track of where we are in descending
    // through the tree to find an insertion point
    BSTNode *currPtr = rootPtr;
    BSTNode *prevPtr = NULL;
    T currVal;

    // If tree is empty, then insert the first node at root

    if (this->isEmpty()) {
        rootPtr = new BSTNode(el);
        return true;
    }

    // Descend the tree for a proper place to put the input value
    // The input value will become a new leaf on the tree
    // NOTE: This does NOT perform any tree balancing!

    while (currPtr != NULL) {
        // prevPtr remembers where we were, so when currPtr becomes
        // NULL, prevPtr will point to the node where we will
        // attach the new value as a child
        prevPtr = currPtr;

        // Descend the tree - go left if value is less than
        // current node, go right if greater than current node
        currVal = currPtr->getEl();
        if (el < currVal)
            currPtr = currPtr->getLeftChildPtr();
        else if (el > currVal)
            currPtr = currPtr->getRightChildPtr();
        else {
            // If the value matches one already in the tree, we
            // DON'T add it to the tree and instead just return
            cout << "Value NOT inserted - already in the tree! \n";
            return false;
        }
    }

    // When we get here, we've found the place to attach the new node
    // Create a new node and attach it as a left or right child
    // to the node that prevPtr is pointing to

    if (el < prevPtr->getEl())
        prevPtr->setLeftChildPtr(new BSTNode(el));
    else
        prevPtr->setRightChildPtr(new BSTNode(el));

    return true;
}

// **********************************************************
// ADD CODE FOR METHODS HERE
// **********************************************************

static void preorderHelper(BSTNode* node){
    if(node == NULL)
        return;

    cout << node->getEl() << " ";
    preorderHelper(node->getLeftChildPtr());
    preorderHelper(node->getRightChildPtr());
}

void BST::preorderTraversal() const {
    if(rootPtr == NULL){
        cout << "***TREE IS EMPTY***" << endl;
        return;
    }

    preorderHelper(rootPtr);
    cout << endl;
}

static void inorderHelper(BSTNode* node){
    if(node == NULL)
        return;

    inorderHelper(node->getLeftChildPtr());
    cout << node->getEl() << " ";
    inorderHelper(node->getRightChildPtr());

}

void BST::inorderTraversal() const {
    if(rootPtr == NULL){
        cout << "***TREE IS EMPTY***" << endl;
        return;
    }

    inorderHelper(rootPtr);
    cout << endl;
}

static void postorderHelper(BSTNode* node){
    if(node == NULL)
        return;

    postorderHelper(node->getLeftChildPtr());
    postorderHelper(node->getRightChildPtr());
    cout << node->getEl() << " ";

}

void BST::postorderTraversal() const {
    if(rootPtr == NULL){
        cout << "***TREE IS EMPTY***" << endl;
        return;
    }

    postorderHelper(rootPtr);
    cout << endl;
}

static int countNodesHelper(BSTNode* node){
    if(node == NULL)
        return 0;

    return 1 + countNodesHelper(node->getLeftChildPtr()) + countNodesHelper(node->getRightChildPtr());
}

int BST::countNodes() const{
    return countNodesHelper(rootPtr);
}

static int countLeafsHelper(BSTNode* node){
    if(node == NULL)
        return 0;

    if(node->getLeftChildPtr() == NULL && node->getRightChildPtr() == NULL)
        return 1;

    return countLeafsHelper(node->getLeftChildPtr()) + countLeafsHelper(node->getRightChildPtr());
}

int BST::countLeafs() const{
    return countLeafsHelper(rootPtr);
}

int BST::countInterior() const{
    return countNodes() - countLeafs();
}

static int treeHeightHelper(BSTNode* node){
    if(node == NULL)
        return -1;

    int leftHeight = treeHeightHelper(node->getLeftChildPtr());
    int rightHeight = treeHeightHelper(node->getRightChildPtr());

    if(leftHeight >= rightHeight)
        return 1 + leftHeight;
    else
        return 1 + rightHeight;

}

int BST::treeHeight() const{
    return treeHeightHelper(rootPtr);
}

bool BST::deleteNode(T el) {
    BSTNode* targetNode = rootPtr;
    BSTNode* parentNode = NULL;

    while(targetNode != NULL && targetNode->getEl() != el){
        parentNode = targetNode;
        if(el < targetNode->getEl())
            targetNode = targetNode->getLeftChildPtr();
    }

    if(targetNode == NULL)
        return false;

    //targetNode is a leaf node
    if(targetNode->getLeftChildPtr() == NULL && targetNode->getRightChildPtr() == NULL){
        if(parentNode == NULL){
            delete rootPtr;
            rootPtr = NULL;
        }
        else{
            if(parentNode->getLeftChildPtr() == targetNode)
                parentNode->setLeftChildPtr(NULL);
            else
                parentNode->setRightChildPtr(NULL);
            delete targetNode;
        }
        return true;
    }

    //targetNode has only one child
    if(targetNode->getLeftChildPtr() == NULL || targetNode->getRightChildPtr() == NULL){
        BSTNode* childNode;


        if(targetNode->getLeftChildPtr() != NULL)
            childNode = targetNode->getLeftChildPtr();
        else
            childNode = targetNode->getRightChildPtr();

        if(parentNode == NULL){
            delete rootPtr;
            rootPtr = childNode;
        }
        else{
            if(parentNode->getLeftChildPtr() == targetNode)
                parentNode->setLeftChildPtr(childNode);
            else
                parentNode->setRightChildPtr(childNode);
            delete targetNode;
        }
        return true;
    }

    //target has 2 children (Delete by copying)
    BSTNode* repParentNode = targetNode;
    BSTNode* rep = targetNode->getLeftChildPtr();
    while(rep->getRightChildPtr() != NULL){
        repParentNode = rep;
        rep = rep->getRightChildPtr();
    }

    targetNode->setEl(rep->getEl());

    BSTNode* repChildNode = rep->getLeftChildPtr();
    if(repParentNode->getLeftChildPtr() == rep)
        repParentNode->setLeftChildPtr(repChildNode);
    else
        repParentNode->setRightChildPtr(repChildNode);

    delete rep;
    return true;
}

bool BST::leftRotation(BSTNode& gp, BSTNode& par, BSTNode& ch) {
    BSTNode* gpPtr = &gp;
    BSTNode* parPtr = &par;
    BSTNode* chPtr = &ch;

    bool parIsLeft = (gpPtr->getLeftChildPtr() == parPtr);
    bool parIsRight = (gpPtr->getRightChildPtr() == parPtr);

    if(!parIsLeft && !parIsRight)
        return false;

    if(parPtr->getRightChildPtr() != chPtr)
        return false;

    BSTNode* chLeft = chPtr->getLeftChildPtr();
    parPtr->setRightChildPtr(chLeft);
    chPtr->setLeftChildPtr(parPtr);

    if(rootPtr == parPtr){
        rootPtr = chPtr;
    }
    else{
        if(parIsLeft)
            gpPtr->setLeftChildPtr(chPtr);
        else
            gpPtr->setRightChildPtr(chPtr);
    }

    return true;
}

bool BST::rightRotation(BSTNode& gp, BSTNode& par, BSTNode& ch) {
    BSTNode* gpPtr = &gp;
    BSTNode* parPtr = &par;
    BSTNode* chPtr = &ch;

    bool parIsLeft = (gpPtr->getLeftChildPtr() == parPtr);
    bool parIsRight = (gpPtr->getRightChildPtr() == parPtr);

    if (!parIsLeft && !parIsRight)
        return false;

    if(parPtr->getLeftChildPtr() != chPtr)
        return false;

    BSTNode* chRight = chPtr->getRightChildPtr();
    parPtr->setLeftChildPtr(chRight);
    chPtr->setRightChildPtr(parPtr);

    if(rootPtr == parPtr){
        rootPtr = chPtr;
    }
    else{
        if(parIsLeft)
            gpPtr->setLeftChildPtr(chPtr);
        else
            gpPtr->setRightChildPtr(chPtr);

    }

    return true;
}

