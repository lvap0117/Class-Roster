#pragma once
#include "student.h"
using namespace std;

class Roster {
public:
    // Accessor
    Student** getStudents();

    // Parsing
    void parse(string studentData);

    // E3a.
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // E3b. 
    void remove(string studentID);

    // E3c. 
    void printAll();

    // E3d. 
    void printAverageDaysInCourse(string studentID);

    // E3e.
    void printInvalidEmails();

    // E3f.
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // F5. Destructor
    ~Roster();

private:
    int lastPointedTo = -1;
    const static int numStudents = 5;
    // E1.  Array of pointers to hold the data provided in the “studentData Table.”
    Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};
;