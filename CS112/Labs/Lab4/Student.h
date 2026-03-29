// CS 112 Spring 2025 - Week 04 Lab
// Matthew Anderson

#ifndef STUDENT_H
#define STUDENT_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Student {
  public:

    Student(string,int);


    void display() const;

    string studentName;
    int studentID;
    int studentGrades[3];

  private:


};

#endif /* STUDENT_H */

