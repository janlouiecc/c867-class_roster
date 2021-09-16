#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
using std::string;

class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age{ 0 };
	int daysToCompleteCourse[3];
	DegreeProgram degreeProgram;

public:
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram);

	void setStudentID(string studentID);
	
	string getStudentID() { return this->studentID; };
	
	void setFirstName(string firstName);
	
	string getFirstName() { return this->firstName; }; 
	
	void setLastName(string lastName);
	
	string getLastName() { return this->lastName; };
	
	void setEmailAddress(string emailAddress);
	
	string getEmailAddress() { return this->emailAddress; };
	
	void setAge(int age);
	
	int getAge() { return this->age; };
	
	void setDaysToCompleteCourse(int* daysToCompleteCourse);
	
	int* getDaysToCompleteCourse() { return this->daysToCompleteCourse; };

	void setDegreeProgram(DegreeProgram degreeProgram);
		
	DegreeProgram getDegreeProgram() { return this->degreeProgram;  };

	void Print();
};

#endif