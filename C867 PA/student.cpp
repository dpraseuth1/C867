#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "student.hpp"
#include "degree.hpp"

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (i = 0; i < daysInCourseArraySize; i++) {this->daysInCourse[i] = 0;}
    this->degreeProgram = DegreeProgram::SECURITY;
}

//full constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (i = 0; i < daysInCourseArraySize; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
    
}

Student::~Student() {
    
}

//getters
string Student::getStudentID() {
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmail() {
    return email;
}
int Student::getAge() {
    return age;
}
int* Student::getDaysInCourse() {
    return daysInCourse;
}
DegreeProgram Student::getDegreeProgram(){
    return degreeProgram;
}

//setters
void Student::setStudentID(string studentIDSet) {
    this->studentID = studentIDSet;
}
void Student::setFirstName(string firstNameSet) {
    this->firstName = firstNameSet;
}
void Student::setLastName(string lastNameSet) {
    this->lastName = lastNameSet;
}
void Student::setEmail(string emailSet) {
    this->email = emailSet;
}
void Student::setAge(int ageSet) {
    this->age = ageSet;
}
void Student::setDaysInCourse(int daysInCourseSet[]) {
    for(i = 0; i < daysInCourseArraySize; i++) {
        this->daysInCourse[i] = daysInCourseSet[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeSet) {
    this->degreeProgram = degreeSet;
}


//print student data
void Student::print() {
    cout << getStudentID() << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge() << "\t";
    cout << "daysInCourse:  {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} " << "Degree Program: ";
    cout << degreeProgramStrings[(int)getDegreeProgram()] << endl;
}
