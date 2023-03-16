#include <iostream>
#include <string>
using namespace std;
#include "roster.hpp"


void Roster::parseData(string row) {
    int rhs = row.find(",");
    string studentID = row.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string email = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    DegreeProgram degreeProgram;
    string degreeProgramStrings = row.substr(lhs, rhs - lhs);
    if (degreeProgramStrings == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (degreeProgramStrings == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (degreeProgramStrings == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }

    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}


//add method
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[Student::daysInCourseArraySize]{daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

//prints student data
void Roster::printAll() {
    cout << "Displaying All Students:" << endl;
    for (i = 0; i <= Roster::lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

//print by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastIndex; i++)
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
}


//print invalid emails. Criteria for a valid email is to include '@' and '.' and not include ' '
void Roster::printInvalidEmails() {
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = classRosterArray[i]->getEmail();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
            cout << email << " is invalid" << endl;
    }
}

//print avg number of days by student ID
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << "Student ID: " << studentID << ", average days in course is: ";
            cout << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3 << endl;
        }
    }
}

//remove by student id
void Roster::remove(string studentID) {
        bool success = false;
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (classRosterArray[i]->getStudentID() == studentID)
            {
                success = true;
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
                Roster::lastIndex--;
            }
        }
        if (success)
        {
            cout << "Student ID: " << studentID << " removed." << endl;
            printAll();
        }
        else cout << "Student ID: " << studentID << " not found." << endl;

}


//destructor
Roster::~Roster()
{
    for (int i = 0; i < numStudents; ++i)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
