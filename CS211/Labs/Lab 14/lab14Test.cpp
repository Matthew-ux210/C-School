//  CS 211 Fall 2025 - Week 14 Lab
//  B-Trees in C++

#include <cstdlib>
#include <iostream>
#include <string>
#include "BTree.h"

using namespace std;

int main() {
    cout << boolalpha;

    // TESTS THE B-TREE METHODS

    // CREATING A TEST B-TREE

    BTree *myBTree = new BTree();

    // GIVING THE TEST B-TREE A ROOT NODE

    BTreeNode *newNode = new BTreeNode();
    myBTree->setRoot(newNode);

    // POPULATING THE TEST B-TREE ROOT NODE WITH VALUES 100,200,300,400

    for (int i=0; i<M-1; i++) {
        newNode->setKey(i, 100*(i+1));
        newNode->incKeyTally();
    }

    // CREATING CHILDREN NODES IN TEST B-TREE WITH ROOM TO GROW
    myBTree->getRoot()->setLeaf(false);

    for (int i=0; i<M; i++) {
        // CREATE A NEW CHILD NODE
        newNode = new BTreeNode();
        //cout << "New child node " << newNode << endl;
        // SET NEW NODE TO BE A CHILD Of ROOT NODE
        myBTree->getRoot()->setPointer(i, newNode);
        // POPULATE CHILD NODE WITH SOME VALUES
        for (int j=0; j<2; j++) {
            newNode->incKeyTally();
            newNode->setKey(j, (100*i + 10*(j+1)));
        }
    }

     // PRINTING TEST B-TREE

    cout << "*** PRINTING OUT CURRENT B-TREE CONTENTS ***" << endl
         << "(SHOULD SEE 10 20 100 110 120 200 210 220 300 310 320 400 410 420)" << endl;
    myBTree->printBTree();

    // THE CODE BELOW CAN BE UNCOMMENTED TO RUN INSERTS AND DELETES

    // INSERT VALUES INTO EACH NODE - 15, 105, 225, 315
    // SHOULD BE INSERTED IN SORTED ORDER

    cout << endl;
    cout << "*****************************************************" << endl;
    cout << "*** INSERT TESTS - SHOULD GET 5 trues             ***" << endl;
    cout << "*****************************************************" << endl;
    cout << endl;

    cout << myBTree->insertKey(15) << " ";
    cout << myBTree->insertKey(105) << " ";
    cout << myBTree->insertKey(225) << " ";
    cout << myBTree->insertKey(240) << " ";
    cout << myBTree->insertKey(315) << endl << endl;

    cout << "*** PRINTING OUT CURRENT B-TREE CONTENTS ***" << endl
         << "*** If inserts successful, should see:" << endl
         << "(10 15 20 100 105 110 120 200 210 220 225 240 300 310 315 320)" << endl;
    myBTree->printBTree();


    // AT THIS POINT, ALL THE CHILD NODES ARE FULL, SO THE NEXT ONE SHOULD FAIL
    cout << endl;
    cout << "*****************************************************" << endl;
    cout << "*** INSERT TEST - SHOULD GET false FROM splitNode ***" << endl;
    cout << "*****************************************************" << endl;
    cout << endl;

    cout << myBTree->insertKey(250) << endl;

    // NOW, LET'S DELETE SOME VALUES FROM THE NODES

    cout << endl;
    cout << "*****************************************************" << endl;
    cout << "*** DELETE TESTS - SHOULD GET true true true true ***" << endl;
    cout << "*****************************************************" << endl;
    cout << endl;

    cout << myBTree->deleteKey(10) << " ";
    cout << myBTree->deleteKey(20) << " ";
    cout << myBTree->deleteKey(210) << " ";
    cout << myBTree->deleteKey(315) << endl << endl;

    cout << "*** PRINTING OUT CURRENT B-TREE CONTENTS ***" << endl
         << "*** If deletes successful, should see:" << endl
         << "(15 100 105 110 120 200 220 225 240 300 310 320 400 410 420)" << endl;
    myBTree->printBTree();

    // AT THIS POINT, ONE CHILD NODE HAS ONLY ONE NODE, SO DELETE SHOULD FAIL
    cout << endl;
    cout << "******************************************************" << endl;
    cout << "*** DELETE TEST - SHOULD GET false FROM mergeNodes ***" << endl;
    cout << "******************************************************" << endl;
    cout << endl;

    cout << myBTree->deleteKey(15) << endl;

    return EXIT_SUCCESS;
}

