#include <iostream>
#include "roster.h"

using namespace std;

int main() {
    const string studentData[] = {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Lois Vernon,Pua,lpua@wgu.edu,24,10,08,12,SOFTWARE"

    };
    const int numStudents = 5;

    // F1. 
    cout << "C867 Scripting & Programming: Applications" << endl;
    cout << "Language - C++" << endl;
    cout << "Student ID - 008443322" << endl;
    cout << "Name - Lois Vernon A. Pua" << endl;
    cout << endl;

    // F2.
    Roster classRoster;

    // F3. 
    for (int i = 0; i < numStudents; ++i) {
        classRoster.parse(studentData[i]);
    }

    // F4.
    // Prints all students in the roster
    classRoster.printAll();
    // Prints any invalid emails found in thhe roster
    classRoster.printInvalidEmails();
    // Prints the average num of days to complete three courses
    for (int i = 0; i < numStudents; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.getStudents()[i]->getStudentID());
    }
    // Prints students by degree program
    for (int i = 0; i < 4; ++i) {
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }
    // Removes student with ID A3 and then prints other students in roster
    classRoster.remove("A3");
    // Tries to remove student A3 again, shows that it fails
    classRoster.remove("A3");

    cout << "DONE." << endl;

    //F5. 
    classRoster.~Roster();

    return 0;
}





