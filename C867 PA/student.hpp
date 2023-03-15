#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "degree.hpp"

class Student{
public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    ~Student();
    
    //getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    //setters
    void setStudentID(string studentIDSet);
    void setFirstName(string firstNameSet);
    void setLastName(string lastNameSet);
    void setEmail(string emailSet);
    void setAge(int ageSet);
    void setDaysInCourse(int daysInCourseSet[]);
    void setDegreeProgram(DegreeProgram degreeSet);
    
    //print function
    void print();
    
    const static int daysInCourseArraySize = 3;
    
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[daysInCourseArraySize];
    DegreeProgram degreeProgram;
    int i = 0;
};

