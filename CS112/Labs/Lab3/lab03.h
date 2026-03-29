// CS 112 Spring 2025 - Week 03 Lab
// Overloading and Call by Reference
// Do NOT submit this file to Canvas!

#ifndef LAB03_H
#define LAB03_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Call By Value functions

void displayCallByValue(int);
void displayCallByValue(double);
void displayCallByValue(bool);
void displayCallByValue(string);

// Call By Reference functions

void displayCallByRef(int&);
void displayCallByRef(double&);
void displayCallByRef(bool&);
void displayCallByRef(string&);

void getEmployeeInfo(string&, int&, double&, bool&);

#endif /* LAB03_H */
