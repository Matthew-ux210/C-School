//Created by: Matthew Anderson - 9/21/25

#include <cstdlib>
#include <iostream>
#include <string>

#include "listPlay.h"

using namespace std;

void listPlay(){

    Node *head = NULL;
    Node *tail = NULL;

    int userInt;

    while(true){
        cout << "Please Enter a Numeric Value (Enter -1 to Quit): " << endl;
        cin >> userInt;

        if(userInt == -1)
            break;

        Node *newNode = new Node(userInt);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }

        else{
            tail->setLink(newNode);
            tail = newNode;
        }
    }

    cout << endl;
    cout << "Linked List Contains the Following Numbers: " << endl;

    Node *currentVal = head;

    while (currentVal != NULL){
        cout << currentVal->getData() << " ";
        currentVal = currentVal->getLink();
    }

    cout << endl;

    currentVal = head;

    while (currentVal != NULL){
        Node *nextVal = currentVal->getLink();
    }

    currentVal = head;
    while (currentVal != NULL) {
        Node *nextVal = currentVal->getLink();
        delete currentVal;
        currentVal = nextVal;
    }
}
