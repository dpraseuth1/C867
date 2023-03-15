#include <iostream>
#include <string>
using namespace std;
#include "roster.hpp"



int main()
{
    cout << "--------------------------------------------" << endl;
    cout << "Scripting and Programming Applications C867" << endl;
    cout << "Created using C++ by" << endl;
    cout << "David Praseuth | Student ID: 010343266" << endl;
    cout << "--------------------------------------------" << endl;
    
    
    const int numStudents = 5;
    const string studentData[] =
        {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,David,Praseuth,dpraseu@wgu.edu,27,12,21,50,SOFTWARE"
        };
    
    //create an instance of the Roster class called classRoster.
        Roster classRoster;

        //add each student to classRoster.
        for (int i = 0; i < numStudents; i++) {
            classRoster.parse1(studentData[i]);
        }

        //classRoster.printAll();
        classRoster.printAll();
        cout << endl;

        //classRoster.printInvalidEmails();
        cout << "Invalid Email Addresses" << endl;
        classRoster.printInvalidEmails();
        cout << endl;

        //loop through classRosterArray and for each element:
        //classRoster.printAverageDaysInCourse(/*current_object's student id);
        cout << "Average Days In Course" << endl;
        for (int i = 0; i < numStudents; i++) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
        cout << endl;

        //classRoster.printByDegreeProgram(SOFTWARE);
        cout << "List of Software Students" << endl;
        classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
        cout << endl;

        //classRoster.remove("A3");
        classRoster.remove("A3");
        cout << endl;

        //classRoster.printAll();
        classRoster.printAll();
        cout << endl;

        //classRoster.remove("A3");
        //the above line should print a message saying such a student with this ID was not found.
        classRoster.remove("A3");
        cout << endl;

        //implement the destructor to release the memory that was allocated dynamically in Roster.
        //defined in roster.cpp - automatically implemented in main.cpp

        return 0;
    
    
    return 0;
}
