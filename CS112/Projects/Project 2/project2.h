// CS 112 Spring 2025 - Project Assignment 02
// by David C. Tuttle

// DO NOT TURN IN THIS FILE!
// This file is NOT to be submitted with the Project 2
// submission.  ONLY project2.cpp IS TO BE SUBMITTED!
// Your project2.cpp file needs to work with the
// contents of this .h file as currently written.

// NOTE: if you wish to write additional "helper"
// functions to complete the problems of Project 2,
// you do NOT need to put their headers in this file
// because the main() function for testing will never
// directly call those helper functions.

#ifndef PROJECT2_H
#define PROJECT2_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// NAMED CONSTANTS go here - you must make sure to
// #include "project2.h" in the project2.cpp file

const int NUM_DICE = 5;
const int NUM_SIDES = 6;

// Function headers needed for main()

void rollDie(int&);
bool isYahtzee(int[]);
int  mostCommonValue(int[]);
int  yahtzeeTest();

#endif /* PROJECT2_H */

