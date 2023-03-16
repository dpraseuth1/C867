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
    
    Roster classRoster;

    //add each student to classRoster.
        for (int i = 0; i < numStudents; i++) {
            classRoster.parseData(studentData[i]);
        }

    //prints all student data
        classRoster.printAll();
        cout << endl;

    //prints invalid emails
        cout << "Displaying Invalid Email Addresses:" << endl;
        classRoster.printInvalidEmails();
        cout << endl;

    //prints avg day in course
        cout << "Average Days In Course:" << endl;
        for (int i = 0; i < numStudents; i++) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
        cout << endl;

    //prints students by degree type SOFTWARE
        cout << "Students in Software Degree Program:" << endl;
        classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
        cout << endl;

    //remove student A3
        classRoster.remove("A3");
        cout << endl;
        
    //this will notify us that student A3 was not found since student was already removed
        classRoster.remove("A3");
        cout << endl;

    
    
    return 0;
}
