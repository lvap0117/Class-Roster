#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student {
public:
    // Size of array for average days to complete a course
    const static int daysArraySize = 3;

    // D2d. Constructor
    // Blank Constructor
    Student();
    // Constructor with parameters
    Student(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress, int studentAge, int numDays2Complete[], DegreeProgram degreeProgram);

    // Destructor for Requirement F5
    ~Student();

    // D2a. 
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    const int* getNumDaysToComplete();
    DegreeProgram getDegreeProgram();

    // D2b. 
    void setStudentID(string studentID);
    void setFirstName(string studentFirstName);
    void setLastName(string studentLastName);
    void setEmailAddress(string studentEmailAddress);
    void setAge(int studentAge);
    void setNumDaysToComplete(const int numDaysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // D2e. Print function for each specific student data
    void print();

    // D1.  
private:
    string studentID;
    string studentFirstName;
    string studentLastName;
    string studentEmailAddress;
    int studentAge;
    int numDaysToComplete[daysArraySize];
    DegreeProgram degreeProgram;

};