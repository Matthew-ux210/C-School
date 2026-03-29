// CS 112 Spring 2025- Week 04 Lab
// Matthew Anderson

#include <cstdlib>
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(string a_name, int id_num){
    studentName = a_name;
    studentID = id_num;

    //int studentGrades[];

    for(int i = 0; i < 3; i++){
        studentGrades[i] = 0;
    }


}

void Student::display() const {
    cout << "Name: " << studentName << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Student Grades: " << studentGrades[0] << " " << studentGrades[1] << " " << studentGrades[2] << endl;
 }



