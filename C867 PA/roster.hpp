#pragma once
#include "student.hpp"
using namespace std;
#include <iostream>
#include <string>


class Roster
{
public:
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    void parseData(string row);
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
private:
    int lastIndex = -1;
    int i = 0;
};
