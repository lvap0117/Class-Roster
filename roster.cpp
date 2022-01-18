#include <sstream>
#include "roster.h"

using namespace std;


Student** Roster::getStudents() {
    return Roster::classRosterArray;
}

// E2.  
void Roster::parse(string studentData) {
    DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
    if (studentData.back() == 'Y') {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (studentData.back() == 'K') {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (studentData.back() == 'S') {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
  

    string items[9];
    int rawData1 = 0;
    int rawData2 = 0;
    for (int i = 0; i < 9; ++i) {
        rawData1 = studentData.find(",", rawData2);
        items[i] = studentData.substr(rawData2, rawData1 - rawData2);
        rawData2 = rawData1 + 1;
    }
    add(items[0], items[1], items[2], items[3], stoi(items[4]), stoi(items[5]), stoi(items[6]), stoi(items[7]), degreeProgram);
}

// E3a. 
void Roster::add(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int numDays2Complete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    // E2. 
    classRosterArray[++lastPointedTo] = new Student(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, numDays2Complete, degreeProgram);
}

// E3b.
void Roster::remove(string studentID) {
    bool success = false;
    for (int i = 0; i <= Roster::lastPointedTo; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            success = true;
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;
            Roster::lastPointedTo--;
        }
    }
    if (success) {
        cout << "Removing " << studentID << endl;
        printAll();
    }
    // E3b. if Student ID = Does  not exist, prints error message
    else {
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }
    cout << endl;
}

// E3c.
void Roster::printAll() {
    cout << "Displaying all students:" << endl;
    for (int i = 0; i <= Roster::lastPointedTo; ++i) {
        Roster::classRosterArray[i]->print();
    }
    cout << endl;
}

// E3d. 
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::lastPointedTo; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << "Student ID: " << studentID << " averages ";
            cout << (classRosterArray[i]->getNumDaysToComplete()[0] + classRosterArray[i]->getNumDaysToComplete()[1] + classRosterArray[i]->getNumDaysToComplete()[3]) / 3;
            cout << " days in a course." << endl;
        }
    }
}

// E3e. 
// Emails must have "@" and "."
// Emails must NOT have a space
void Roster::printInvalidEmails() {
    cout << "Displaying invalid emails:" << endl;
    for (int i = 0; i <= Roster::lastPointedTo; ++i) {
        string email = Roster::getStudents()[i]->getEmailAddress();
        // Checks for spaces
        if (email.find(' ') != string::npos) {
            cout << email << " - no spaces allowed." << endl;
        }
        // Checks for periods
        else if (email.find('.') == string::npos) {
            cout << email << " - missing a period" << endl;
        }
        // Checks for @ symbol
        else if (email.find('@') == string::npos) {
            cout << email << " - missing an @ symbol" << endl;
        }
    }
    cout << endl;
}

// E3f.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    int j = static_cast<int>(degreeProgram);
    cout << endl;
    cout << "Showing students in degree program: " << degreeProgramStrings[j] << endl;
    for (int i = 0; i <= Roster::lastPointedTo; ++i) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < numStudents; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}