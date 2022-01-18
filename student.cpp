#include <iostream>
#include "student.h"



Student::Student()
{
}

// Constructor (with parameters)
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress, int studentAge, int numDaysToComplete[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->studentFirstName = studentFirstName;
    this->studentLastName = studentLastName;
    this->studentEmailAddress = studentEmailAddress;
    this->studentAge = studentAge;
    for (int i = 0; i < daysArraySize; ++i) {
        this->numDaysToComplete[i] = numDaysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}

// Destructor
Student::~Student() {}

// Used in Roster::printAll(); for printing one student at a time;
void Student::print() {
    cout << this->studentID << '\t' << '\t';
    cout << "First Name: " << this->studentFirstName << '\t' << '\t';
    cout << "Last Name: " << this->studentLastName << '\t' << '\t';
    cout << "Email: " << this->studentEmailAddress << '\t' << '\t';
    cout << "Age: " << this->studentAge << '\t' << '\t';
    cout << "Days in Course: " << this->numDaysToComplete[0] << '\t';
    cout << this->numDaysToComplete[1] << '\t';
    cout << this->numDaysToComplete[2] << '\t' << '\t';
    cout << "Degree Program: " << degreeProgramStrings[(int)this->degreeProgram] << endl;
}

// Mutators
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string studentFirstName) {
    this->studentFirstName = studentFirstName;
}
void Student::setLastName(string studentLastName) {
    this->studentLastName = studentLastName;
}
void Student::setEmailAddress(string studentEmailAddress) {
    this->studentEmailAddress = studentEmailAddress;
}
void Student::setAge(int studentAge) {
    this->studentAge = studentAge;
}
void Student::setNumDaysToComplete(const int numDaysToComplete[]) {
    for (int i = 0; i < daysArraySize; ++i) {
        this->numDaysToComplete[i] - numDaysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Accessors
string Student::getStudentID() {
    return this->studentID;
}
string Student::getFirstName() {
    return this->studentFirstName;
}
string Student::getLastName() {
    return this->studentLastName;
}
string Student::getEmailAddress() {
    return this->studentEmailAddress;
}
int Student::getAge() {
    return this->studentAge;
}
const int* Student::getNumDaysToComplete() {
    return this->numDaysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}
